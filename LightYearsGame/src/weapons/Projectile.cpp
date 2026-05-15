// In the name of Allah

#include "weapons/Projectile.h"
#include "framework/AppContext.h"

LY::Projectile::Projectile(
            World *owningWorld,
            const std::string &uid,
            const std::string &texturePath,
            const sf::Vector2f initVelocity,
            const float xInitPos,
            const float yInitPos
            ) : MovingActor(owningWorld, uid, texturePath, xInitPos, yInitPos, initVelocity) {
    positionChange = AppContext::projectileConfig.initPosChange ;
}

LY::Projectile::~Projectile() {
    LOG("Projectile Destroyed") ;
}

void LY::Projectile::Progress(const float deltaTime) {
    Actor::Progress(deltaTime);
    ChangePosition() ;
    Move(deltaTime) ;
}

void LY::Projectile::ChangePosition() {
    mDirection.y -= positionChange ;
}



