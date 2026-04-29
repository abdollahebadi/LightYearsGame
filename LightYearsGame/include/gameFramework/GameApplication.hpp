// In the name of Allah
//

#pragma once
#include <framework/Application.hpp>

namespace LY {
    class GameApplication : public Application {
    public:
        GameApplication(
            unsigned int windowWidth,
            unsigned int windowHeight,
            const std::string& windowTitle,
            std::uint32_t windowStyle,
            float targetFrameRate
            );
    };
}

