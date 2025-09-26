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
protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCore")
    TObjectPtr<class UCameraRigControllerComponent> CameraRigControllerComponent;
private:

};