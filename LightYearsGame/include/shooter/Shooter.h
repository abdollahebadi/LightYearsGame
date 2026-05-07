// In the name of Allah

#pragma once

#include "framework/Actor.h"

namespace LY {

    class Shooter {
    public:
        virtual ~Shooter() = default ;

        Shooter(Actor* owner) { owningActor = owner ; }

        virtual void Shoot() = 0 ;

    // protected:
    //     virtual void Progress(float deltaTime) ;

    private:
        // We can use a raw pointer here since the actor outlives the shooter and thus this raw pointer will not become
        // dangled.
        Actor* owningActor ;

    } ;
}
