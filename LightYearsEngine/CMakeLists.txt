# In the name of Allah
# This is the top level CmakeLists file for the light year project that I am going with the Udemy tutorial.

add_library(${LIGHT_YEARS_ENGINE_TARGET_NAME} STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Core.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/World.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Actor.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Object.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/AssetManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/AppContext.cpp
)

target_include_directories(${LIGHT_YEARS_ENGINE_TARGET_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# The below section for fetching the SFML lib from github and then building it for he project.
include(FetchContent)

set(SFML_LIB_NAME SFML)

FetchContent_Declare(
        ${SFML_LIB_NAME}
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW TRUE
        EXCLUDE_FROM_ALL
)

set(BUILD_SHARED_LIBS OFF)
FetchContent_MakeAvailable(${SFML_LIB_NAME})

target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC SFML::Graphics)