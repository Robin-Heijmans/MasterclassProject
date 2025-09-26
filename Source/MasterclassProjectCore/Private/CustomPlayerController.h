#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "CustomPlayerController.generated.h"

UCLASS()
class ACustomPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ACustomPlayerController(const FObjectInitializer& ObjectInitializer);
public:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
public:
    
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCore")
    TObjectPtr<class UCameraRigControllerComponent> CameraRigControllerComponent;
private:

};