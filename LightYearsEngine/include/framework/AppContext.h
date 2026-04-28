// In the name of Allah

#pragma once

#include "framework/Core.h"
#include "framework/Configs.h"
#include "framework/AssetManager.h"

namespace LY {
    class AppContext {
    public:

        static void Init(ENVIRONMENT env) ;

        static AssetManager& Assets() ;
    private:

        AppContext() = default ;

        inline static ENVIRONMENT currentEnvironment ;

        inline static unique<AppContext> appContext ;

        inline static unique<AssetManager> _assetManager ;

    } ;
}



