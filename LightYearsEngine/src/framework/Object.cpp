// In the name of Allah


#include "framework/Object.h"
#include "framework/Core.h"

LY::Object::Object() : isPendingDestroy(false) {

}

LY::Object::~Object() {
    LOG("Object Destroyed...!!") ;
}

void LY::Object::Destroy() {
    isPendingDestroy = true ;
}

bool LY::Object::isObjectPendingDestroy() {
    return isPendingDestroy ;
}
