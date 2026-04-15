# In the name of Allah
# This is the top level CmakeLists file for the light year project that I am going with the Udemy tutorial.

cmake_minimum_required(VERSION 3.8)

# Declare configs for the project such as name current version and programming languages used
project(LightYears VERSION 1.0.0 LANGUAGES C CXX)

# sets the minimum C++ version needed
set(CMAKE_CXX_STANDARD 14)

# Enforces the minimum c++ version
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# This disables language extensions to make it compatible in platforms.
set(CMAKE_CXX_EXTENSIONS OFF)

# create a variable in cmake
set(LIGHT_YEAR_GAME_TARGET_NAME LightYearGame)

# Add this line to redirect all of the executables to the top level build folder, this needs to be added before the
# add subdirectory clause.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# add the source sub directory to the build
add_subdirectory(src)

