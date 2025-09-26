#include "Actors/CameraRigZoomComponent.h"
#include "Actors/CameraRig.h"
#include "GameFramework/SpringArmComponent.h"

UCameraRigZoomComponent::UCameraRigZoomComponent(const FObjectInitializer& ObjectInitializer){
    ZoomSpeed = 200.f;
    MinArmLength = 300.f;
    MaxArmLength = 1500.f;
}

void UCameraRigZoomComponent::BeginPlay()
{
    Super::BeginPlay();

    CameraRig = Cast<ACameraRig>(GetOwner());
    if (!CameraRig) {
        UE_LOG(LogTemp, Warning, TEXT("CameraRigZoomComponent: Owner is not a CameraRig"));
    }
}

void UCameraRigZoomComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCameraRigZoomComponent::OnZoomCamera(float Value) {
    if (CameraRig && ensure(CameraRig->SpringArm)) {
        if (FMath::IsNearlyZero(Value)) return;
        
        float desired = CameraRig->SpringArm->TargetArmLength - Value * ZoomSpeed * GetWorld()->GetDeltaSeconds();
        desired = FMath::Clamp(desired, MinArmLength, MaxArmLength);
        CameraRig->SpringArm->TargetArmLength = desired;
    }
}