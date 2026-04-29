// In the name of Allah

#include "framework/MathUtils.h"
#include <cmath>

namespace  LY {

    float RadiansToDegree(const float radians) {
        return radians * 180.0f / PI ;
    }

    float DegreesToRadians(const float degrees) {
        return degrees * PI / 180.0f ;
    }

    sf::Vector2f RotationToVector(const float degrees) {
        const auto radians = DegreesToRadians(degrees) ;
        return sf::Vector2f(std::cos(radians), std::sin(radians)) ;
    }

}
