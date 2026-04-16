# In the name of Allah
# This is the cmakelists file for the source folder

add_executable(${LIGHT_YEAR_GAME_TARGET_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/framework/Application.cpp
)

target_include_directories(${LIGHT_YEAR_GAME_TARGET_NAME}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

# set the standard for the game target only.
target_compile_features(
        ${LIGHT_YEAR_GAME_TARGET_NAME}
        PRIVATE
        cxx_std_14
)

target_link_libraries(${LIGHT_YEAR_GAME_TARGET_NAME} PUBLIC SFML::Graphics)

