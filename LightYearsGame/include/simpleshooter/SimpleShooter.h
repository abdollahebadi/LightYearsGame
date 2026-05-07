// In the name of Allah

#pragma once

#include "shooter/Shooter.h"


namespace LY {
    class SimpleShooter : public Shooter {

    public:
        SimpleShooter(Actor* owner) ;

        void Shoot() override ;

    } ;
}