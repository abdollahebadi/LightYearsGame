
// In the name of Allah


#pragma once

#include "framework/Actor.h"

namespace LY {
    class Bullet  : public Actor {
    public:
        Bullet(
            World *owningWorld,
            const std::string &uid, 
            const std::string &texturePath, 
            float xInitPos,
            float yInitPos,
            float speed = 100.0f
            ) ;
        
    protected:
        void Progress(float deltaTime) override ;
    
    private:
        float mSpeed ;

        sf::Vector2f mMovement ;

    } ;
}