// In the name of Allah

#pragma once

#include <string>

#include "Core.h"
#include "framework/Object.h"
#include "SFML/Graphics.hpp"

namespace LY {

    class World ;


    /**
    * The ACtor class wilL not have any movement related variable such as position or velocity.
    * These physical attributes are delegated to each child class so that the mechanics can be different
    * for each child that moves. In addition, Actor is a general base class that can encompass any object in the
    * world from non-moving to moving and that is another reason that movement attributes are not implemented
    * in this level but rather in the next level which are any children that require movement as their nature.
    **/
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

        World& GetWorld() const ;

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
