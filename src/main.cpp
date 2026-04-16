// In the name of Allah
// Created by abdollah-ebadi on 4/14/26.
//

#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char** argv) {

    // Create the window to show on the screen.
    sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "SFML works!" );

    // Create the circle and set its color.
    sf::CircleShape shape( 100.f );
    shape.setFillColor( sf::Color::Green );

    // This is the main loop of the window, that will run if the state of the window is open.
    while ( window.isOpen() )
    {
        // We are polling for any event that happens in the context of this window.
        while ( const std::optional event = window.pollEvent() )
        {
            // The window will not close automatically with just getting the close event
            // We need to close the window manually.
            if ( event->is<sf::Event::Closed>() )
                window.close(); // This should change the state of the window to close.
        }

        window.clear();
        window.draw( shape );
        window.display();
    }

    if (!window.isOpen()) {
        std::cout << "Window is closed, we are shutting down...!" << std::endl ;
    }
}