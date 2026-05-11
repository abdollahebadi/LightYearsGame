// In the name of Allah

#pragma once
#include "framework/Actor.h"
#include "framework/World.h"

namespace LY {
    class Spaceship : public Actor {
    public:
        Spaceship(World *world, std::string uid, const std::string& texturePath, float xInitPos, float yInitPos) ;

        void SetVelocity(sf::Vector2f velocity) ;

    protected:
        void Progress(float deltaTime) override ;

    private:
        sf::Vector2f mVelocity;

    } ;
}