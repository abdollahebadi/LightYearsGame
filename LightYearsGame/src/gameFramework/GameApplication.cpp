// In the name of Allah

#include "gameFramework/GameApplication.hpp"
#include "framework/World.h"
#include "framework/AppContext.h"
#include "framework/Configs.h"
#include "player/PlayerSpaceship.h"


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

    LY::AppContext::Init(ENVIRONMENT::PROD) ;

    const auto firstWorld = SpawnWorld<World>() ;

    // firstWorld.lock()->SpawnActor<Actor>(
    //     "1",
    //     "assets/SpaceShooterRedux/PNG/playerShip1_blue.png",
    //     100.0f,
    //     100) ;
    //
    // firstWorld.lock()->SpawnActor<Actor>(
    //     "2" ,
    //     "assets/SpaceShooterRedux/PNG/playerShip1_green.png",
    //     200.0f,
    //     200.0f) ;

    firstWorld.lock()->SpawnActor<PlayerSpaceship>(
        "3" , "assets/SpaceShooterRedux/PNG/playerShip1_red.png" ,
        300 ,
        600) ;
}

