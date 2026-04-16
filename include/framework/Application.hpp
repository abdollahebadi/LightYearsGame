// In the name of Allah
#pragma once

#include <SFML/Graphics.hpp>

namespace LY {
    class Application {
    public:
        Application() ;
        void Run() ;

    private:
        sf::RenderWindow mWindow ;
    };
}