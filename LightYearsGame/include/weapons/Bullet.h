// In the name of Allah

#pragma once

#include "shooter/Shooter.h"
#include <SFML/System.hpp>

namespace LY {
    class Bullet : public Shooter {

    public:
        Bullet(Actor* owner, float coolDownPeriod = 1.f) ;

        void ShootImpl() override ;

        bool isCooledDown() const override ;

    private:
        sf::Clock coolDownClock ;
        float coolDownTime ;
    } ;
}