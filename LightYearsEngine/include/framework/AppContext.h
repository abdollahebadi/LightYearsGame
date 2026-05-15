// In the name of Allah

#pragma once

#include "framework/Core.h"
#include "framework/Configs.h"
#include "framework/AssetManager.h"

namespace LY {
    class AppContext {

    private:
        AppContext() = default ;

        inline static ENVIRONMENT currentEnvironment ;

        inline static unique<AppContext> appContext ;

        inline static unique<AssetManager> _assetManager ;

        inline static sf::Vector2u windowSize ;

        struct ProjectileInitValues {
            float initPosChange ;
            sf::Vector2f initVelocity ;
        };

        struct LaserGunInitValues {
            float coolDownPeriod ;
        };

    public:
        inline static ProjectileInitValues projectileConfig { 2.0f , {0.f , 30.f} } ;

        inline static LaserGunInitValues laserGunConfig {0.15 } ;

        static void Init(ENVIRONMENT env, unsigned int windowWidth, unsigned int windowHeight) ;

        static AssetManager& Assets() ;

        static sf::Vector2u getWindowSize() ;


    } ;
}



