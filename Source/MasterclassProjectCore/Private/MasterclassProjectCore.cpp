#include "MasterclassProjectCore.h"
#include "Modules/ModuleManager.h"

#include "Log.h"

void MasterclassProjectCore::StartupModule()
{
    UE_LOG(LogMasterclassProjectCore, Log, TEXT("MasterclassProjectCore module starting up"));
}

void MasterclassProjectCore::ShutdownModule()
{
    UE_LOG(LogMasterclassProjectCore, Log, TEXT("MasterclassProjectCore module shutting down"));
}

IMPLEMENT_PRIMARY_GAME_MODULE(MasterclassProjectCore, MasterclassProjectCore, "MasterclassProjectCore");