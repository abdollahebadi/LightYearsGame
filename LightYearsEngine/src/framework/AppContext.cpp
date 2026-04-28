// In the name of Allah

#include "framework/AppContext.h"
#include "framework/Configs.h"


void LY::AppContext::Init(const ENVIRONMENT env) {
    currentEnvironment = env ;
    appContext = unique<AppContext>(new AppContext());
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
