// In the name of Allah
#pragma once

#include <SFML/Graphics.hpp>
#include "framework/World.h"
#include "framework/Core.h"

namespace LY {
    class Application {
    public:
        Application(
            unsigned int windowWidth,
            unsigned int windowHeight,
            const std::string& windowTitle,
            std::uint32_t style,
            float targetFrameRate
            ) ;
        virtual ~Application() = default ;
        void Run() ;

        /**
         * Since this is a template function it can only live in the header file, you cannot move it to the source file
         * We can separate the definition from the declaration of course, but the definition will again be in this header
         * file but after the class declaration. For example:
        **/
        // template<typename worldType>
        // weak<worldType> SpawnWorld() ;

        template<typename WorldType>
        weak<WorldType> SpawnWorld() {
            /**
             static_assert is a compile-time check — if the condition is false, the compiler stops and shows your
             message as the error.
             static_assert(std::is_base_of<World, worldType>::value, "worldType must derive from World");
             Breaking it down:
                - std::is_base_of<World, worldType>::value — evaluates to true or false at compile time, checking if
                  worldType inherits from World
                - If false → compilation fails with your message: "worldType must derive from World"
                - If true → nothing happens, compilation continues normally
            **/
            static_assert(std::is_base_of_v<World, WorldType>, "WorldType must derive from World");

            // you can't use = to assign a raw pointer to a shared_ptr in C++11 and later — it must be direct
            // initialization {} or std::make_shared, so we cannot use: shared<WorldType> newWorld = new WorldType(this) ;
            shared<WorldType> newWorld { new WorldType(this) } ;

            currentWorld = newWorld ;
            return newWorld ;
        }

    private:
        /**
        so the internal and non-internal pattern implemented for functions results in the logic to be separable between
        the engine and the game. Andon the other side the NVI pattern enforces this by making the game facing function
        only overridable and not callable.
        The two ideas work together:
        - Internal/non-internal split — separates where the logic lives (engine vs game)
        - NVI (private virtual) — enforces how it can be used (game can only override Tick/Render, never
        call or bypass them directly)

        Without the private, the split would just be a convention — nothing stops a careless subclass from calling
        Tick() directly or misusing it. Making them private virtual turns that convention into a
        compiler-enforced contract.
        So the design gives you two guarantees:
        1. Engine logic (timing, world updates, rendering setup) always runs — game can't skip it
        2. Game logic stays in its designated hooks — it can't reach into engine internals
        **/
        void TickInternal(float deltaTime) ;
        void RenderInternal() ;
        virtual void Tick(float deltaTime) ;
        virtual void Render() ;

        sf::RenderWindow mWindow ;
        float mTargetFrameRate ;
        sf::Clock mTick ;

        shared<World> currentWorld ;
    };

    /**
     * The following line will need to be un-commented if we want to separate the declaration and definition of a template
     * class function.
    **/
    // template<typename WorldType>
    // weak<WorldType> SpawnWorld() {
    //
    // }


}