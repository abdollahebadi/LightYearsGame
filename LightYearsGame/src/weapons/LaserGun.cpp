// In the name of Allah

#include "weapons/LaserGun.h"

#include "framework/AppContext.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "weapons/Projectile.h"


LY::LaserGun::LaserGun(Actor *owner, const float coolDownPeriod) : Shooter(owner),
                                                                   coolDownClock {},
                                                                   coolDownTime(coolDownPeriod) {
    LOG("Laser gun Created..!!") ;
}

void LY::LaserGun::ShootImpl() {
    coolDownClock.restart() ;
    //LOG("Laser gun shoots") ;

    const auto x = owningActor->GetActorPosition() .x ;
    const auto y = owningActor->GetActorPosition() .y - (owningActor->GetActorBounds().size.y) ;

    //need to spawn a new bullet here.
    auto ret = owningActor->GetWorld().SpawnActor<Projectile>(
        "Laser",
        "assets/SpaceShooterRedux/PNG/Lasers/laserBlue01.png",
        LY::AppContext::projectileConfig.initVelocity,
        x,
        y
        ) ;
}

bool LY::LaserGun::isCooledDown() const {
    if (coolDownClock.getElapsedTime().asSeconds() > coolDownTime) {
        return true ;
    }
    return false ;
}


