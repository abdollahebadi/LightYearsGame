// In the name of Allah

#pragma once

#include "shooter/Shooter.h"
#include <SFML/System.hpp>

namespace LY {
    class LaserGun : public Shooter {

    public:
        LaserGun(Actor* owner, float coolDownPeriod) ;

        void ShootImpl() override ;

        bool isCooledDown() const override ;

    private:
        sf::Clock coolDownClock ;
        float coolDownTime ;
    } ;
}