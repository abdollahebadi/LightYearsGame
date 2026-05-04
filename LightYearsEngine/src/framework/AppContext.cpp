// In the name of Allah

#include "framework/AppContext.h"
#include "framework/Configs.h"


void LY::AppContext::Init(const ENVIRONMENT env, const unsigned int windowWidth, const unsigned int windowHeight) {
    currentEnvironment = env ;
    appContext = unique<AppContext>(new AppContext());
    windowSize = sf::Vector2u(windowWidth, windowHeight) ;
    if (currentEnvironment == ENVIRONMENT::PROD) {
        _assetManager = std::make_unique<AssetManager>(env) ;
    }
    else { }
}

LY::AssetManager &LY::AppContext::Assets() {
    if (!appContext) {
        LOG("AppContext not initialized. Please call AppContext::Init() first.") ;
        throw std::runtime_error("AppContext not initialized. Please call AppContext::Init() first.") ;
    }
    return *_assetManager ;
}

sf::Vector2u LY::AppContext::getWindowSize() {
    return windowSize ;
}
