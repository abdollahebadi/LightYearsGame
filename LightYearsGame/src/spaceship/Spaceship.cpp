// In the name of Allah

#include "spaceship/Spaceship.h"

LY::Spaceship::Spaceship(
    World *world, std::string uid,
    const std::string &texturePath,
    const float xInitPos,
    const float yInitPos) : Actor(world, uid, texturePath, xInitPos, yInitPos) {

    setVelocity({ 0 , -100.0f}) ;
}

void LY::Spaceship::Progress(const float deltaTime) {
    SetActorPositionOffset(mVelocity * deltaTime) ;
}

void LY::Spaceship::setVelocity(const sf::Vector2f velocity) {
    mVelocity = velocity;
}



