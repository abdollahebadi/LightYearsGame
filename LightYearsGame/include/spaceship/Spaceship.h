// In the name of Allah

#pragma once
#include "framework/MovingActor.h"
#include "framework/World.h"

namespace LY {
    class Spaceship : public MovingActor {
    public:
        Spaceship(
            World *world,
            std::string uid,
            const std::string& texturePath,
            float xInitPos,
            float yInitPos,
            sf::Vector2f initVelocity
            ) ;

    protected:
        void Progress(float deltaTime) override = 0 ;

    } ;
}