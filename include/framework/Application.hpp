// In the name of Allah
#pragma once

#include <SFML/Graphics.hpp>

namespace LY {
    class Application {
    public:
        Application() ;
        virtual ~Application() = default ;
        void Run() ;
        virtual void Tick(float deltaTime) ;
        virtual void Render() ;

    private:
        void TickInternal(float deltaTime) ;
        void RenderInternal() ;
        sf::RenderWindow mWindow ;
        float mTargetFrameRate ;
        sf::Clock mTick ;
    };
}