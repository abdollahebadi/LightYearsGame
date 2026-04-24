// In the name of Allah

#include "gameFramework/GameApplication.hpp"
#include "framework/World.h"
#include "framework/Actor.h"

LY::Application* GetApplication() {
    return new LY::GameApplication(
        1024,
        800,
        "Light Years",
        sf::Style::Titlebar | sf::Style::Close,
        60.0f);
}

LY::GameApplication::GameApplication(
    const unsigned int windowWidth,
    const unsigned int windowHeight,
    const std::string& windowTitle,
    const std::uint32_t windowStyle,
    const float targetFrameRate) : Application(windowWidth, windowHeight, windowTitle, windowStyle, targetFrameRate) {
    const auto firstWorld = SpawnWorld<World>() ;

    auto ac4  = firstWorld.lock()->SpawnActor<Actor>(
        "1",
        "assets/SpaceShooterRedux/PNG/playerShip1_blue.png",
        0,
        0) ;

    firstWorld.lock()->SpawnActor<Actor>(
        "2" ,
        "assets/SpaceShooterRedux/PNG/playerShip1_green.png",
        100,
        100) ;

    // for (int i = 0; i < 100000000; i++) {
    //
    // }
    // ac4.lock()->Destroy() ;
}

