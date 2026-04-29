// In the name of Allah

#pragma once

#include <SFML/Graphics.hpp>


namespace LY {

      const float PI = 3.14159265358979323846f;

      float RadiansToDegree(float radians);

      float DegreesToRadians(float degrees);

      sf::Vector2f RotationToVector(float degrees) ;

}