// In the name of Allah

#pragma once

#include "framework/Actor.h"
#include "framework/Core.h"

namespace LY {

    class Application ;

    class World
    {
    public:

        World(Application* owningApp) ;

        void BeginWorldInternal() ;

        void ProgressWorldInternal(float deltaTime) ;

        virtual ~World() ;

        template <typename ActorType>
        weak<ActorType> SpawnActor(std::string uid) ;

    private:
        Application* owningApp ;

        bool worldStarted ;

        List<shared<Actor>> activeActors ;

        List<shared<Actor>> pendingActors ;

        virtual void BeginWorld() ;

        virtual void ProgressWorld(float deltaTime) ;
    } ;

    template<typename ActorType>
    weak<ActorType> World::SpawnActor(std::string uid) {
        static_assert(std::is_base_of_v<Actor, ActorType>, "ActorType must derive from Actor");
        shared<ActorType> newActor {new ActorType(this , uid)} ;
        pendingActors.push_back(newActor) ;
        return newActor ;
    }
}
