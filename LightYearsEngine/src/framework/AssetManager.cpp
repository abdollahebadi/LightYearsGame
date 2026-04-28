// In the name of Allah
#include "framework/AssetManager.h"

LY::AssetManager::AssetManager(const ENVIRONMENT env) : currentEnv{env} {
    if (currentEnv == ENVIRONMENT::TEST) {
        LoadTestEnvironment() ;
    }
}

void LY::AssetManager::LoadTestEnvironment() {
    LOG("Test Environment is being loaded...!!!") ;
}

LY::shared<sf::Texture> LY::AssetManager::getTexture(const std::string path) {
    // First check to see if we have the texture in the dictionary
    const auto txt = loadedTextures.find(path) ;
    if ( txt != loadedTextures.end() ) {
        return txt->second ;
    }

    // If not then load the texture from the path and then insert it in the dictionary and return that.
    auto newTexture = std::make_shared<sf::Texture>() ;
    if (newTexture->loadFromFile(path)) {
        // loaded correctly
        loadedTextures.insert({path, newTexture}) ;
        return newTexture ;
    }
    // If load from disk was unsuccessful then return a null pointer
    return shared<sf::Texture> {nullptr} ;
}

void LY::AssetManager::CleanUp() {

    for ( auto iter = loadedTextures.begin() ; iter != loadedTextures.end() ; ) {
        if (iter->second.use_count() == 1) {
            iter = loadedTextures.erase(iter) ;
        }
        else {
            ++iter ;
        }
    }
}



