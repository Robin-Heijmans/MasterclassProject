#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "CameraRigZoomComponent.generated.h"

UCLASS()
class UCameraRigZoomComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCameraRigZoomComponent(const FObjectInitializer& ObjectInitializer);

public:
    void BeginPlay() override;
    void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
    void OnZoomCamera(float Value);

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowerDefenseCamera")
    float ZoomSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowerDefenseCamera")
    float MinArmLength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowerDefenseCamera")
    float MaxArmLength;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="TowerDefenseCamera")
    TObjectPtr<class ACameraRig> CameraRig;

};