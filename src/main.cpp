// In the name of Allah
// Created by abdollah-ebadi on 4/14/26.
//


#include <memory>
#include "framework/Application.hpp"

int main(int argc, char** argv) {
    const auto app = std::make_unique<LY::Application>();
    app->Run() ;
}