#pragma once
    
#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class MasterclassProjectCore : public IModuleInterface
{
public:
    static inline MasterclassProjectCore& Get()
    {
        return FModuleManager::LoadModuleChecked<MasterclassProjectCore>("MasterclassProjectCore");
    }

    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("MasterclassProjectCore");
    }

    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};