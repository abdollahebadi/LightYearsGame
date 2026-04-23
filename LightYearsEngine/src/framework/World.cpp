// In the name of Allah

#include "framework/World.h"
#include "framework/Core.h"

LY::World::World(Application *owningApp) : owningApp(owningApp) , worldStarted(false) { }

void LY::World::BeginWorldInternal() {
    if (!worldStarted) {
        worldStarted = true;
        BeginWorld();
    }
}

void LY::World::BeginWorld() { LOG("World started..!!") ; }

void LY::World::ProgressWorldInternal(const float deltaTime) {

    // We first progress the state of the elements in the world and then the world itself.
    for (const auto& actor : pendingActors) {
        activeActors.push_back(actor) ;
        actor->BeginActorInternal() ;
    }
    pendingActors.clear() ;

    for (const auto& actor : activeActors) {
        actor->ProgressActorInternal(deltaTime) ;
    }

    ProgressWorld(deltaTime) ;
}

void LY::World::ProgressWorld(const float deltaTime) {
    LOG("World progressed at frame rate: %f", (1.0f/deltaTime) ) ;
}

LY::World::~World() { }
