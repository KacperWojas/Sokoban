cmake_minimum_required(VERSION 3.28)
project(Sokoban LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

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

target_link_libraries(Sokoban PRIVATE
        raylib
)
