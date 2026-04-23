// In the name of Allah

#pragma once

#include <string>

namespace LY {

    class World ;

    class Actor {
    public:
        Actor(World* owningWorld, std::string uid) ;
        virtual ~Actor();

        void BeginActorInternal() ;
        void ProgressActorInternal(float deltaTime) ;

    private:
        World* owningWorld ;
        bool actorStarted ;
        std::string actorUID ;

        virtual void BeginActor() ;
        virtual void ProgressActor(float deltaTime) ;
    };
}