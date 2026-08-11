cmake_minimum_required(VERSION 4.2)
project(Sokoban)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 6.0
)
FetchContent_MakeAvailable(raylib)

add_executable(Sokoban src/main.cpp
        src/Views/ConsoleView.cpp
        src/Views/ConsoleView.h)

target_link_libraries(Sokoban raylib)