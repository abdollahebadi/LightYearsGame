// In the name of Allah

#pragma once

#include "spaceship/Spaceship.h"
#include "shooter/Shooter.h"

namespace LY {
    class World ;
    class PlayerSpaceship : public Spaceship {
    public:
        PlayerSpaceship(World* world, std::string uid, const std::string& texturePath, float xInitPos, float yInitPos) ;

        void SetSpeed(float speed) ;

        float GetSpeed() const ;

    private:
        float mSpeed ;

        sf::Vector2f mMovement ;

        shared<Shooter> currentShooter ;

        void HandleInput() ;

        void ConsumeInput() ;

        void NormalizeInput() ;

        void ClampInputToWindow() ;

        void Progress(float deltaTime) override ;

    } ;
}

