// In the name of Allah

#pragma once

#include <complex>
#include <SFML/Graphics.hpp>


namespace LY {

      const float PI = 3.14159265358979323846f;

      float RadiansToDegree(float radians);

      float DegreesToRadians(float degrees);

      sf::Vector2f RotationToVector(float degrees) ;

      template<typename T>
      void NormalizeVector(sf::Vector2<T>& vector) {
            T magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y) ;
            if (static_cast<float>(magnitude) != 0.0f)
                  vector /= magnitude ;
      } ;

}