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

        template <typename ActorType, typename ... Args>
        weak<ActorType> SpawnActor(Args... args) ;

        void Render(sf::RenderWindow& window) ;

    private:
        Application* owningApp ;

        bool worldStarted ;

        List<shared<Actor>> activeActors ;

        List<shared<Actor>> pendingActors ;

        virtual void BeginWorld() ;

        virtual void ProgressWorld(float deltaTime) ;
    } ;

    template<typename ActorType, typename ... Args>
    weak<ActorType> World::SpawnActor(Args... args) {
            static_assert(std::is_base_of_v<Actor, ActorType>, "ActorType must derive from Actor");
            shared<ActorType> newActor {new ActorType(this, args...)} ;
            pendingActors.push_back(newActor) ;
            return newActor ;
    }
}
