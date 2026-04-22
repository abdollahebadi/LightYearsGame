// In the name of Allah

#pragma once

namespace LY {

    class Application ;

    class World
    {
    public:
        World(Application* owningApp) ;

        void BeginWorldInternal() ;

        void ProgressWorldInternal(float deltaTime) ;

        virtual ~World() ;

    private:
        Application* owningApp ;
        bool worldStarted ;

        void BeginWorld() ;
        void ProgressWorld(float deltaTime) ;
    } ;
}