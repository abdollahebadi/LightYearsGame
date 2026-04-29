// In the name of Allah

#include "EntryPoint.hpp"
#include <memory>

int main(int argc, char** argv) {
    std::unique_ptr<LY::Application> appPtr = std::unique_ptr<LY::Application>(GetApplication());
    appPtr->Run();
}
