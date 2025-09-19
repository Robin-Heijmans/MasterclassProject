#include "CustomGameMode.h"

#include "CustomPawn.h"
#include "CustomPlayerController.h"
#include "CustomHUD.h"
#include "CustomPlayerState.h"
#include "CustomGameState.h"


ACustomGameMode::ACustomGameMode(const FObjectInitializer& ObjectInitializer) {
    DefaultPawnClass = ACustomPawn::StaticClass();
    PlayerControllerClass = ACustomPlayerController::StaticClass();
    HUDClass = AHUD::StaticClass();
    PlayerStateClass = ACustomPlayerState::StaticClass();
    GameStateClass = AGameState::StaticClass();
}