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

        void ProgressInternal(float deltaTime) ;

        void RenderActor(sf::RenderWindow& window) ;

        void SetActorPosition(sf::Vector2f position) ;

        void SetActorPositionOffset(sf::Vector2f offset) ;

        void SetActorRotation(float degrees) ;

        void SetActorRotationOffset(float offset) ;

        sf::Vector2f GetActorPosition() const ;

        float GetActorRotationInDegrees() const ;

        sf::Vector2f GetActorForwardDirection() const ;

        sf::Vector2f GetActorRightDirection() const ;

        sf::FloatRect GetActorBounds() const ;

    protected:
        virtual void Progress(float deltaTime) ;

    private:
        World* owningWorld ;
        bool actorStarted ;
        std::string actorUID ;

        shared<sf::Texture> acTexture ;
        sf::Sprite acSprite ;

        sf::FloatRect actorBounds ; ;

        virtual void BeginActor() ;


        void CenterPivot() ;
    };
}
