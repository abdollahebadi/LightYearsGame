// In the name of Allah

#include "spaceship/Spaceship.h"

LY::Spaceship::Spaceship(
    World *world, std::string uid,
    const std::string &texturePath,
    const float xInitPos,
    const float yInitPos,
    const sf::Vector2f initVelocity
    ) : MovingActor(world, uid, texturePath, xInitPos, yInitPos, initVelocity) { }

void LY::Spaceship::Progress(const float deltaTime) {
    MovingActor::Progress(deltaTime) ;
    Move(deltaTime) ;
}




