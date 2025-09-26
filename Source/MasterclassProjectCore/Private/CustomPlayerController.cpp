#include "CustomPlayerController.h"
#include "Actors/CameraRigComponent.h"

ACustomPlayerController::ACustomPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    CameraRigControllerComponent = CreateDefaultSubobject<UCameraRigControllerComponent>(TEXT("CameraRigControllerComponent"));
}

void ACustomPlayerController::BeginPlay() {
    Super::BeginPlay();
}

