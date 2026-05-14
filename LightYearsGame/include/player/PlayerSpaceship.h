// In the name of Allah

#pragma once

#include "spaceship/Spaceship.h"
#include "shooter/Shooter.h"

namespace LY {
    class World ;
    class PlayerSpaceship : public Spaceship {
    public:
        PlayerSpaceship(
            World* world,
            std::string uid,
            const std::string& texturePath,
            sf::Vector2f initVelocity,
            float xInitPos,
            float yInitPos
            ) ;

        sf::Vector2f GetVelocity() const ;

    protected:
        void Progress(float deltaTime) override ;

    private:

        shared<Shooter> currentShooter ;

        void HandleInput() ;

        void ConsumeInput(float deltaTime) ;

        void NormalizeInput() ;

        void ClampInputToWindow() ;
    } ;
}

