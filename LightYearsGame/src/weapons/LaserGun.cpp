// In the name of Allah

#include "weapons/LaserGun.h"
#include "framework/Core.h"


LY::LaserGun::LaserGun(Actor *owner, const float coolDownPeriod) : Shooter(owner),
coolDownClock {},
coolDownTime(coolDownPeriod) {
    LOG("Simple Shooter Created..!!") ;
}

void LY::LaserGun::ShootImpl() {
    coolDownClock.restart() ;
    LOG("Shot by Simple Shooter") ;
}

bool LY::LaserGun::isCooledDown() const {
    if (coolDownClock.getElapsedTime().asSeconds() > coolDownTime) {
        return true ;
    }
    return false ;
}


