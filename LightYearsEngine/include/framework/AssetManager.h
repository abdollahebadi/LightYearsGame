// In the name of Allah

#pragma once

#include "framework/Core.h"
#include "framework/Configs.h"
#include <string>
#include <SFML/Graphics.hpp>

#include "SFML/Graphics/Texture.hpp"

namespace LY {
    class AssetManager {

    public:
        AssetManager(ENVIRONMENT env) ;

        shared<sf::Texture> getTexture(std::string path) ;

        void CleanUp() ;

    private:
        Dictionary<std::string, shared<sf::Texture>> loadedTextures ;
        void LoadTestEnvironment() ;
        ENVIRONMENT currentEnv = ENVIRONMENT::PROD ;

    } ;
}



