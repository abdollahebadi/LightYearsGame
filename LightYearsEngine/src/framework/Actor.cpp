// In the name of Allah

#include "framework/Actor.h"
#include "framework/Core.h"

LY::Actor::Actor(World* owningWorld, std::string uid) : owningWorld(owningWorld), actorStarted(false), actorUID(uid) {

}

LY::Actor::~Actor() {

}

void LY::Actor::BeginActor() {
     LOG("Actor %s Started", actorUID.c_str());
}

void LY::Actor::BeginActorInternal() {
     if (!actorStarted) {
         actorStarted = true ;
         BeginActor() ;
     }
}

void LY::Actor::ProgressActor(const float deltaTime) {
   LOG("Actor %s progressing with frame rate: %f", actorUID.c_str() , (1.0f / deltaTime) ) ;
}

void LY::Actor::ProgressActorInternal(const float deltaTime) {
    ProgressActor(deltaTime) ;
}
