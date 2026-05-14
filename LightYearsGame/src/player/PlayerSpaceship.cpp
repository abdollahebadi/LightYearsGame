// In the name of Allah

#include "player/PlayerSpaceship.h"

#include "framework/AppContext.h"
#include "framework/MathUtils.h"
#include "weapons/LaserGun.h"

LY::PlayerSpaceship::PlayerSpaceship(
    World *world,
    const std::string uid,
    const std::string &texturePath,
    const sf::Vector2f initVelocity,
    const float xInitPos,
    const float yInitPos
    ): Spaceship(
        world,
        uid,
        texturePath,
        xInitPos,
        yInitPos,
        initVelocity) {

    // Start with a simple shooter for the spaceship.
    currentShooter = std::make_shared<LaserGun>(this) ;
}

sf::Vector2f LY::PlayerSpaceship::GetVelocity() const {
    return mVelocity ;
}

void LY::PlayerSpaceship::HandleInput() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        mDirection.x = -1 ;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        mDirection.x = +1 ;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        mDirection.y = -1 ;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        mDirection.y = +1 ;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        currentShooter->Shoot() ;
    }

    NormalizeInput() ;
    ClampInputToWindow() ;

}

void LY::PlayerSpaceship::ConsumeInput(const float deltaTime) {
    Spaceship::Move(deltaTime) ;
    mDirection = { 0.f , 0.f } ;
}

void LY::PlayerSpaceship::NormalizeInput() {
    NormalizeVector(mDirection) ;
}

void LY::PlayerSpaceship::ClampInputToWindow() {
    const auto windowWidth = LY::AppContext::getWindowSize().x ;
    const auto windowHeight = LY::AppContext::getWindowSize().y ;

    const auto currentPosition = GetActorPosition() ;


    if ( (currentPosition.x - GetActorBounds().size.x / 2) <= 0 && mDirection.x < 0) {
        mDirection.x = 0.0f ;
    }

    if ( (currentPosition.y - GetActorBounds().size.y / 2) <= 0 && mDirection.y < 0) {
        mDirection.y = 0.0f ;
    }

    if ( (currentPosition.x +  GetActorBounds().size.x / 2) >= windowWidth && mDirection.x >= 0) {
        mDirection.x = 0.0f ;
    }

    if ( (currentPosition.y + GetActorBounds().size.y / 2) >= windowHeight && mDirection.y >= 0) {
        mDirection.y = 0.0f ;
    }
}

void LY::PlayerSpaceship::Progress(const float deltaTime) {
    Spaceship::Progress(deltaTime) ;
    HandleInput() ;
    ConsumeInput(deltaTime) ;
}


