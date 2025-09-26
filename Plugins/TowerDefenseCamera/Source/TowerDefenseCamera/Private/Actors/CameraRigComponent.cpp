#include "Actors/CameraRigComponent.h"
#include "Actors/CameraRig.h"
#include "Log.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerController.h"

DEFINE_LOG_CATEGORY(LogTowerDefenseCamera);

UCameraRigControllerComponent::UCameraRigControllerComponent(const FObjectInitializer& ObjectInitializer) {
    PrimaryComponentTick.bCanEverTick = false;
}

void UCameraRigControllerComponent::BeginPlay() {
    Super::BeginPlay();

    EnsureCameraRig();
}

void UCameraRigControllerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason) {
    Super::EndPlay(EndPlayReason);
    // Nothing to implement yet
}

void UCameraRigControllerComponent::EnsureCameraRig() {
    if (SpawnedCameraRig && !SpawnedCameraRig->IsPendingKillPending()) return;

    APlayerController* playerController = CastChecked<APlayerController>(GetOwner());
    APawn* pawn = playerController->GetPawn();

    if (!pawn){
        //log warning "No Pawn possessed yet; wait until later"
        UE_LOG(LogTowerDefenseCamera, Warning, TEXT("CameraRigInputComponent: No Pawn possessed yet; wait until later"));
        return;
    }
    FVector spawnPosition = pawn->GetActorLocation();
    FRotator spawnRotation = FRotator::ZeroRotator;

    if (CameraRigTemplate) {
        SpawnedCameraRig = GetWorld()->SpawnActor<ACameraRig>(CameraRigTemplate, spawnPosition, spawnRotation);
    }
    else {
        for (TActorIterator<ACameraRig> It(GetWorld()); It; ++It){
            SpawnedCameraRig = *It;
            break;
        }
    }

    if (SpawnedCameraRig) {
        playerController->SetViewTarget(SpawnedCameraRig);
    }
    else{
        UE_LOG(LogTowerDefenseCamera, Warning, TEXT("CameraRigInputComponent: Could not create or find a CameraRig"));
    } 
}