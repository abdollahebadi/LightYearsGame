// In the name of Allah

#include "player/PlayerSpaceship.h"

LY::PlayerSpaceship::PlayerSpaceship(
    World *world,
    const std::string uid,
    const std::string &texturePath,
    const float xInitPos,
    const float yInitPos): Spaceship(world, uid, texturePath, xInitPos, yInitPos), mSpeed(0) {
    SetSpeed(200.0f) ;
}

void LY::PlayerSpaceship::SetSpeed(const float speed) {
    mSpeed = speed ;
}

float LY::PlayerSpaceship::GetSpeed() const {
    return mSpeed ;
}

void LY::PlayerSpaceship::HandleInput() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        mMovement.x = -1 ;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        mMovement.x = +1 ;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        mMovement.y = -1 ;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        mMovement.y = +1 ;
    }
}

void LY::PlayerSpaceship::ConsumeInput() {
    SetVelocity(mMovement * mSpeed) ;
    mMovement = sf::Vector2f(0,0) ;
}

void LY::PlayerSpaceship::Progress(const float deltaTime) {
    Spaceship::Progress(deltaTime) ;
    HandleInput() ;
    ConsumeInput() ;

}


