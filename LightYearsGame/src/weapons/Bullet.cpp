// In the name of Allah

#include "weapons/Bullet.h"
#include "framework/Core.h"


LY::Bullet::Bullet(Actor *owner, const float coolDownPeriod) : Shooter(owner),
coolDownClock {},
coolDownTime(coolDownPeriod) {
    LOG("Simple Shooter Created..!!") ;
}

void LY::Bullet::ShootImpl() {
    coolDownClock.restart() ;
    LOG("Shot by Simple Shooter") ;
}

bool LY::Bullet::isCooledDown() const {
    if (coolDownClock.getElapsedTime().asSeconds() > coolDownTime) {
        return true ;
    }
    return false ;
}


