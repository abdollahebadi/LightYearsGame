
// In the name of Allah


#pragma once

#include "framework/Actor.h"
#include "framework/MovingActor.h"

namespace LY {
    class Projectile  : public MovingActor {
    public:
        Projectile(
            World *owningWorld,
            const std::string &uid, 
            const std::string &texturePath,
            sf::Vector2f initVelocity,
            float xInitPos,
            float yInitPos
            ) ;

        ~Projectile() override ;
        
    protected:
        void Progress(float deltaTime) override ;

    private:
        void ChangePosition() ;

        float positionChange ;
    } ;
}
