# In the name of Allah
# This is the top level CmakeLists file for the light year project that I am going with the Udemy tutorial.

cmake_minimum_required(VERSION 3.28)

# Declare configs for the project such as name current version and programming languages used
project(LightYears VERSION 1.0.0 LANGUAGES C CXX)

# Enforces the minimum c++ version
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# This disables language extensions to make it compatible in platforms.
set(CMAKE_CXX_EXTENSIONS OFF)

# create a variable in cmake
set(LIGHT_YEAR_GAME_TARGET_NAME LightYearGame)

# Add this line to redirect all of the executables to the top level build folder, this needs to be added before the
# add subdirectory clause.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set usage of rpath and run path to false
set(CMAKE_SKIP_BUILD_RPATH TRUE)

# Set $ORIGIN as the RUNPATH using CMake's own variable
set(CMAKE_INSTALL_RPATH "$ORIGIN")

# tells CMake to use the install RPATH during the build stage as well, otherwise $ORIGIN would only apply during install
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

# The below section for fetching the SFML lib from github and then building it for he project.
include(FetchContent)

set(SFML_LIB_NAME SFML)

FetchContent_Declare(
        ${SFML_LIB_NAME}
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW FALSE
        EXCLUDE_FROM_ALL
)

# Force All libs to build as shared libraries
set(BUILD_SHARED_LIBS ON)

FetchContent_MakeAvailable(${SFML_LIB_NAME})

# add the source sub directory to the build
add_subdirectory(src)

# Install our executable
install(TARGETS ${LIGHT_YEAR_GAME_TARGET_NAME}
        RUNTIME DESTINATION bin
)

# Install SFML shared libraries
install(TARGETS sfml-graphics sfml-window sfml-system
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
)