
// In the name of Allah

#pragma once

#include "Actor.h"

namespace LY {
    class MovingActor : public Actor {
    public:

        MovingActor(World* owningWorld, std::string uid,
                    const std::string& texturePath,
                    float xInitPos, float yInitPos, sf::Vector2f initVelocity) ;

    protected:
        virtual void Move(float deltaTime);

        sf::Vector2f mVelocity;
        sf::Vector2f mDirection;
    } ;
}
