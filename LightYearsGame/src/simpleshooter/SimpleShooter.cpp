// In the name of Allah

#include "simpleshooter/SimpleShooter.h"
#include "framework/Core.h"


LY::SimpleShooter::SimpleShooter(Actor *owner) : Shooter(owner) {
    LOG("Simple Shooter Created..!!") ;
}

void LY::SimpleShooter::Shoot() {
    LOG("Shot by Simple Shooter") ;
}


