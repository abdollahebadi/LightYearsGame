// In the name of Allah

#include "weapons/Bullet.h"

LY::Bullet::Bullet(
            World *owningWorld,
            const std::string &uid,
            const std::string &texturePath,
            const float xInitPos,
            const float yInitPos,
            const float speed
            ) : Actor(owningWorld, uid, texturePath, xInitPos, yInitPos), mSpeed(speed) { }

void LY::Bullet::Progress(const float deltaTime) {
     Actor::Progress(deltaTime);
}

