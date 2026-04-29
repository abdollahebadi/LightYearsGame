// In the name of Allah

#pragma once

#include <string>

#include "Core.h"
#include "framework/Object.h"
#include "SFML/Graphics.hpp"

namespace LY {

    class World ;

    class Actor : public Object {
    public:
        Actor(World* owningWorld, std::string uid, const std::string& texturePath, float xInitPos, float yInitPos) ;
        virtual ~Actor();

        void BeginActorInternal() ;

        void ProgressActorInternal(float deltaTime) ;

        void RenderActor(sf::RenderWindow& window) ;

        void SetActorPosition(sf::Vector2f position) ;

        void SetActorPositionOffset(sf::Vector2f offset) ;

        void SetActorRotation(float degrees) ;

        void SetActorRotationOffset(float offset) ;

        sf::Vector2f GetActorPosition() const ;

        float GetActorRotationInDegrees() const ;

        sf::Vector2f GetActorForwardDirection() const ;

        sf::Vector2f GetActorRightDirection() const ;


    private:
        World* owningWorld ;
        bool actorStarted ;
        std::string actorUID ;

        shared<sf::Texture> acTexture ;
        sf::Sprite acSprite ;

        virtual void BeginActor() ;
        virtual void ProgressActor(float deltaTime) ;
        void CenterPivot() ;
    };
}
