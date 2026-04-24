// In the name of Allah
#include "framework/Application.hpp"
#include "framework/Core.h"
#include "framework/World.h"

namespace LY {
    Application::Application(
        const unsigned int windowWidth,
        const unsigned int windowHeight,
        const std::string& windowTitle,
        const std::uint32_t style,
        const float targetFrameRate
        ) :
    mWindow( sf::VideoMode( { windowWidth, windowHeight } ), windowTitle, style ),
    mTargetFrameRate (targetFrameRate),
    mTick{},
    currentWorld(nullptr)
    { }

    void Application::TickInternal(const float deltaTime) {

        Tick(deltaTime) ;

        if (currentWorld) {
            currentWorld->BeginWorldInternal() ;
            currentWorld->ProgressWorldInternal(deltaTime) ;
        }

    }

    void Application::RenderInternal() {
        mWindow.clear() ;
        Render() ;
        mWindow.display() ;
    }


    void Application::Run() {
        mTick.restart() ;
        float accumulatedTime = 0.0f ;
        float targetDeltaTime = 1.0f / mTargetFrameRate ;

        while ( mWindow.isOpen() )
        {
            // We are polling for any event that happens in the context of this window.
            while (const auto event = mWindow.pollEvent() )
            {
                // The window will not close automatically with just getting the close event
                // We need to close the window manually.
                if ( event->is<sf::Event::Closed>() )
                    mWindow.close(); // This should change the state of the window to close.
            }

            accumulatedTime += mTick.restart().asSeconds() ;
            while (accumulatedTime > targetDeltaTime) {
                accumulatedTime -= targetDeltaTime ;
                TickInternal(targetDeltaTime) ;
                RenderInternal() ;
            }

        }
    }


    // =======================================================
    // Showcase functions implemented here, these must be implemented in the child classes later for the games, we are just
    // showing how they will be used here.
    void Application::Tick(const float deltaTime) {
        LOG("The target frame rate is: %f and we get %f\n", mTargetFrameRate, (1.0f / deltaTime)) ;
    }

    void Application::Render() {
        if (currentWorld) {
            currentWorld->Render(mWindow) ;
        }
    }

}



