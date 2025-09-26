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
    void BindInput(class UEnhancedInputComponent* EnhancedInputComponent);
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowerDefenseCamera")
    TSubclassOf<class ACameraRig> CameraRigTemplate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowerDefenseCamera")
    TObjectPtr<class UInputMappingContext> CameraDefaultInputMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowerDefenseCamera")
    TObjectPtr<class UInputAction> CameraZoomAction;
private:
    void EnsureCameraRig();
    void Input_OnZoomCamera(const struct FInputActionValue& Value);

    UPROPERTY(Transient)
    TObjectPtr<class ACameraRig> SpawnedCameraRig;
};