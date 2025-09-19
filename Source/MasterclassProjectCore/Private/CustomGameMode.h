#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "CustomGameMode.generated.h"

UCLASS()
class ACustomGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:

    ACustomGameMode(const FObjectInitializer& ObjectInitializer);
    
};