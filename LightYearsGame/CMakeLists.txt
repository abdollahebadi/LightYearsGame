# In the name of Allah

add_executable(${LIGHT_YEARS_GAME_TARGET_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/gameFramework/GameApplication.cpp
)

target_include_directories(${LIGHT_YEARS_GAME_TARGET_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PRIVATE ${LIGHT_YEARS_ENGINE_TARGET_NAME})