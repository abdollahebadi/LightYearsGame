// In the name of Allah

#include "weapons/LaserGun.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "weapons/Bullet.h"


LY::LaserGun::LaserGun(Actor *owner, const float coolDownPeriod) : Shooter(owner),
                                                                   coolDownClock {},
                                                                   coolDownTime(coolDownPeriod) {
    LOG("Simple Shooter Created..!!") ;
}

void LY::LaserGun::ShootImpl() {
    coolDownClock.restart() ;
    LOG("Shot by Simple Shooter") ;

    // need to spawn a new bullet here.
    owningActor->GetWorld().SpawnActor<Bullet>(
        "1",
        "assets/SpaceShooterRedux/PNG/Lasers/laserBlue01.png" ,
        300,
        600
        ) ;


}

bool LY::LaserGun::isCooledDown() const {
    if (coolDownClock.getElapsedTime().asSeconds() > coolDownTime) {
        return true ;
    }
    return false ;
}


