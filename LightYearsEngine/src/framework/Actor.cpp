// In the name of Allah

#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AppContext.h"
#include "framework/MathUtils.h"

LY::Actor::Actor(
    World* owningWorld,
    std::string uid,
    const std::string& texturePath,
    const float xInitPos,
    const float yInitPos):
owningWorld(owningWorld),
actorStarted(false),
actorUID(uid),
acTexture(AppContext::Assets().getTexture(texturePath)),
acSprite(*acTexture)
{
    acSprite.setTextureRect(
        sf::IntRect{sf::Vector2i{0, 0}, sf::Vector2i{static_cast<int>(acTexture->getSize().x), static_cast<int>(acTexture->getSize().y)}}) ;

    CenterPivot() ;

    SetActorPosition({xInitPos , yInitPos}) ;
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

void LY::Actor::CenterPivot() {
    const auto bounds = acSprite.getGlobalBounds() ;
    acSprite.setOrigin({bounds.size.x / 2, bounds.size.y / 2}) ;
}

void LY::Actor::ProgressActorInternal(const float deltaTime) {
    ProgressActor(deltaTime) ;
}

void LY::Actor::RenderActor(sf::RenderWindow &window) {
    window.draw(acSprite) ;
}

void LY::Actor::SetActorPosition(const sf::Vector2f position) {
    acSprite.setPosition(position) ;
}

void LY::Actor::SetActorPositionOffset(const sf::Vector2f offset) {
    acSprite.setPosition(GetActorPosition() + offset) ;
}

void LY::Actor::SetActorRotation(const float degrees) {
    acSprite.setRotation(sf::degrees(degrees)) ;
}

void LY::Actor::SetActorRotationOffset(const float offset) {
    acSprite.setRotation(sf::degrees(GetActorRotationInDegrees() + offset)) ;
}

sf::Vector2f LY::Actor::GetActorPosition() const {
    return acSprite.getPosition() ;
}

float LY::Actor::GetActorRotationInDegrees() const {
    return acSprite.getRotation().asDegrees() ;
}

sf::Vector2f LY::Actor::GetActorForwardDirection() const {
    return RotationToVector(GetActorRotationInDegrees()) ;
}

sf::Vector2f LY::Actor::GetActorRightDirection() const {
    return RotationToVector(GetActorRotationInDegrees() + 90.0f) ;
}



