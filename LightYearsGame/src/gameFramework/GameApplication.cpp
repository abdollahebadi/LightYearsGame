// In the name of Allah
//

#include "gameFramework/GameApplication.hpp"
#include "framework/World.h"
#include "framework/Actor.h"

LY::Application* GetApplication() {
    return new LY::GameApplication();
}

LY::GameApplication::GameApplication() {
    const auto firstWorld = SpawnWorld<World>() ;

    auto ac4  = firstWorld.lock()->SpawnActor<Actor>("1") ;
    firstWorld.lock()->SpawnActor<Actor>("2") ;
    firstWorld.lock()->SpawnActor<Actor>("3") ;
    firstWorld.lock()->SpawnActor<Actor>("4") ;

    for (int i = 0; i < 100000000; i++) {

    }
    ac4.lock()->Destroy() ;

}

