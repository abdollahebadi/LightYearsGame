// In the name of Allah

#pragma once

#include "framework/Actor.h"

namespace LY {

    class Shooter {
    public:
        virtual ~Shooter() = default ;

        Shooter(Actor* owner) { owningActor = owner ; }

        void Shoot() {
            if (isCooledDown() && canShoot())
                ShootImpl() ;
        }

        virtual void ShootImpl() = 0 ;

        virtual bool isCooledDown() const = 0 ;

        void setCanShoot(const bool state) { mCanShoot = state ; }

        bool canShoot() const { return mCanShoot ;} ;

    protected:
        // We can use a raw pointer here since the actor outlives the shooter and thus this raw pointer will not become
        // dangled.
        Actor* owningActor ;

    private:
        bool mCanShoot = true ;

    } ;
}
