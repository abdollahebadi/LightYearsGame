
// In the name of Allah

#include "framework/MovingActor.h"

LY::MovingActor::MovingActor(
    World *owningWorld,
    std::string uid,
    const std::string &texturePath,
    const float xInitPos,
    const float yInitPos,
    const sf::Vector2f initVelocity) : Actor(owningWorld, uid, texturePath, xInitPos, yInitPos), mVelocity(initVelocity) {
}

void LY::MovingActor::Move(const float deltaTime) {
    const auto updateVelX = mDirection.x * mVelocity.x * deltaTime ;
    const auto updateVelY = mDirection.y * mVelocity.y * deltaTime ;
    SetActorPositionOffset( sf::Vector2f{updateVelX, updateVelY} );
}



