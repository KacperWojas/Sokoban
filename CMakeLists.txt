cmake_minimum_required(VERSION 3.28)
project(Sokoban LANGUAGES C CXX)

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

FetchContent_Declare(
        pdcurses
        GIT_REPOSITORY https://github.com/Bill-Gray/PDCursesMod.git
        GIT_TAG v4.5.4
)

FetchContent_GetProperties(pdcurses)

if(NOT pdcurses_POPULATED)
    FetchContent_Populate(pdcurses)
endif()

if(WIN32)

    file(GLOB PDCURSES_COMMON_SOURCES
            "${pdcurses_SOURCE_DIR}/pdcurses/*.c"
    )

    file(GLOB PDCURSES_WINCON_SOURCES
            "${pdcurses_SOURCE_DIR}/wincon/*.c"
    )

    add_library(pdcurses STATIC
            ${PDCURSES_COMMON_SOURCES}
            ${PDCURSES_WINCON_SOURCES}
    )

    target_include_directories(pdcurses PUBLIC
            "${pdcurses_SOURCE_DIR}"
            "${pdcurses_SOURCE_DIR}/wincon"
    )

elseif(UNIX)

    file(GLOB PDCURSES_COMMON_SOURCES
            "${pdcurses_SOURCE_DIR}/pdcurses/*.c"
    )

    file(GLOB PDCURSES_VT_SOURCES
            "${pdcurses_SOURCE_DIR}/vt/*.c"
    )

    add_library(pdcurses STATIC
            ${PDCURSES_COMMON_SOURCES}
            ${PDCURSES_VT_SOURCES}
    )

    target_include_directories(pdcurses PUBLIC
            "${pdcurses_SOURCE_DIR}"
            "${pdcurses_SOURCE_DIR}/vt"
    )

endif()

add_executable(Sokoban src/main.cpp
        src/Views/ConsoleView.cpp
        src/Views/ConsoleView.h
        src/Controlers/ConsoleController.cpp
        src/Controlers/ConsoleController.h)

target_link_libraries(Sokoban PRIVATE
        raylib
        pdcurses
)