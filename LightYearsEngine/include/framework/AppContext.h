// In the name of Allah

#pragma once

#include "framework/Core.h"
#include "framework/Configs.h"
#include "framework/AssetManager.h"

namespace LY {
    class AppContext {
    public:

        static void Init(ENVIRONMENT env, unsigned int windowWidth, unsigned int windowHeight) ;

        static AssetManager& Assets() ;

        static sf::Vector2u getWindowSize() ;
    private:

        AppContext() = default ;

        inline static ENVIRONMENT currentEnvironment ;

        inline static unique<AppContext> appContext ;

        inline static unique<AssetManager> _assetManager ;

        inline static sf::Vector2u windowSize ;

    } ;
}



