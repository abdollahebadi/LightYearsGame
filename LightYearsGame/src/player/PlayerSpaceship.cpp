// In the name of Allah

#include "player/PlayerSpaceship.h"

#include "framework/AppContext.h"
#include "framework/MathUtils.h"
#include "weapons/Bullet.h"

LY::PlayerSpaceship::PlayerSpaceship(
    World *world,
    const std::string uid,
    const std::string &texturePath,
    const float xInitPos,
    const float yInitPos): Spaceship(world, uid, texturePath, xInitPos, yInitPos), mSpeed(0) {

    // Start with a simple shooter for the spaceship.
    currentShooter = std::make_shared<Bullet>(this) ;

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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        currentShooter->Shoot() ;
    }

    NormalizeInput() ;
    ClampInputToWindow() ;

}

void LY::PlayerSpaceship::ConsumeInput() {
    SetVelocity(mMovement * mSpeed) ;
    mMovement = sf::Vector2f(0,0) ;
}

void LY::PlayerSpaceship::NormalizeInput() {
    NormalizeVector(mMovement) ;
    //LOG("Input normalized: %f , %f" , mMovement.x , mMovement.y) ;
}

void LY::PlayerSpaceship::ClampInputToWindow() {
    const auto windowWidth = LY::AppContext::getWindowSize().x ;
    const auto windowHeight = LY::AppContext::getWindowSize().y ;

    const auto currentPosition = GetActorPosition() ;


    if ( (currentPosition.x - GetActorBounds().size.x / 2) <= 0 && mMovement.x < 0) {
        mMovement.x = 0.0f ;
    }

    if ( (currentPosition.y - GetActorBounds().size.y / 2) <= 0 && mMovement.y < 0) {
        mMovement.y = 0.0f ;
    }

    if ( (currentPosition.x +  GetActorBounds().size.x / 2) >= windowWidth && mMovement.x >= 0) {
        mMovement.x = 0.0f ;
    }

    if ( (currentPosition.y + GetActorBounds().size.y / 2) >= windowHeight && mMovement.y >= 0) {
        mMovement.y = 0.0f ;
    }
}

void LY::PlayerSpaceship::Progress(const float deltaTime) {
    Spaceship::Progress(deltaTime) ;
    HandleInput() ;
    ConsumeInput() ;

}


