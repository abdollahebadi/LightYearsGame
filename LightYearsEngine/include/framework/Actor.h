// In the name of Allah

#pragma once

#include <string>
#include "framework/Object.h"
#include "SFML/Graphics.hpp"

namespace LY {

    class World ;

    class Actor : public Object {
    public:
        Actor(World* owningWorld, std::string uid, const std::string& texturePath, int xInitPos, int yInitPos) ;
        virtual ~Actor();

        void BeginActorInternal() ;
        void ProgressActorInternal(float deltaTime) ;

        void SetActorResources(const std::string& texturePath, int xInitPos, int yInitPos) ;

        void RenderActor(sf::RenderWindow& window) ;

    private:
        World* owningWorld ;
        bool actorStarted ;
        std::string actorUID ;

        sf::Texture acTexture ;
        sf::Sprite acSprite ;

        virtual void BeginActor() ;
        virtual void ProgressActor(float deltaTime) ;
    };
}
