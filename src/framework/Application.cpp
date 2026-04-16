// In the name of Allah
#include "framework/Application.hpp"

namespace LY {
    Application::Application() : mWindow( sf::VideoMode( { 1000, 600 } ), "Light Years" ) { }

    void Application::Run() {
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
        }
    }
}



