// In the name of Allah

#include "framework/Actor.h"
#include "framework/Core.h"

LY::Actor::Actor(
    World* owningWorld,
    std::string uid,
    const std::string& texturePath,
    const int xInitPos,
    const int yInitPos):
owningWorld(owningWorld),
actorStarted(false),
actorUID(uid),
acTexture(),
acSprite(acTexture)
{
    SetActorResources(texturePath , xInitPos, yInitPos) ;
}

LY::Actor::~Actor() {
   LOG("Actor destroyed") ;
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

void LY::Actor::SetActorResources(const std::string& texturePath, int xInitPos, int yInitPos) {
    if (acTexture.loadFromFile(texturePath)) {

        acSprite.setTexture(acTexture) ;
        acSprite.setTextureRect(sf::IntRect{sf::Vector2i{0, 0}, sf::Vector2i{static_cast<int>(acTexture.getSize().x), static_cast<int>(acTexture.getSize().y)}}) ;
        acSprite.setPosition(sf::Vector2f{static_cast<float>(xInitPos), static_cast<float>(yInitPos)}) ;
    }
}

void LY::Actor::RenderActor(sf::RenderWindow &window) {
    window.draw(acSprite) ;
}
