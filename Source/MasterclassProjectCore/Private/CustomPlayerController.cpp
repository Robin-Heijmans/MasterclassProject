#include "CustomPlayerController.h"
#include "Actors/CameraRigComponent.h"
#include "EnhancedInputComponent.h"

ACustomPlayerController::ACustomPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    CameraRigControllerComponent = CreateDefaultSubobject<UCameraRigControllerComponent>(TEXT("CameraRigControllerComponent"));
}

void ACustomPlayerController::BeginPlay() {
    Super::BeginPlay();
}

void ACustomPlayerController::SetupInputComponent() {
    Super::SetupInputComponent();

    if (CameraRigControllerComponent) {
        UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
        //if (ensureMsgf() {
        //    
        //})
    }
}