#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "CameraRigComponent.generated.h"

UCLASS()
class TOWERDEFENSECAMERA_API UCameraRigControllerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCameraRigControllerComponent(const FObjectInitializer& ObjectInitializer);
protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="OmniCameraCore")
    TSubclassOf<class ACameraRig> CameraRigTemplate;

private:
    void EnsureCameraRig();
    UPROPERTY(Transient)
    TObjectPtr<class ACameraRig> SpawnedCameraRig;
};