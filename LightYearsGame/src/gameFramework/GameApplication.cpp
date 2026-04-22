// In the name of Allah
//

#include "gameFramework/GameApplication.hpp"
#include "framework/World.h"

LY::Application* GetApplication() {
    return new LY::GameApplication();
}

LY::GameApplication::GameApplication() {
    SpawnWorld<World>() ;
}

