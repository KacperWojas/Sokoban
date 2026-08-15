//
// Created by KacperWojas on 15/08/2026.
//

#include <curses.h>

#include "ConsoleController.h"

void ConsoleController::init()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

void ConsoleController::exit()
{
    endwin();
}

Input ConsoleController::GetInput()
{
    int key = getch();
    switch (key)
    {
        case KEY_UP:
        case 'w':
        case 'W':
            return Input::UP;
        case KEY_DOWN:
        case 's':
        case 'S':
            return Input::DOWN;
        case KEY_LEFT:
        case 'a':
        case 'A':
            return Input::LEFT;
        case KEY_RIGHT:
        case 'd':
        case 'D':
            return Input::RIGHT;
        case 'z':
        case 'Z':
            return Input::UNDO;
        case 'x':
        case 'X':
        case 'r':
        case 'R':
            return Input::RESET;
        case '.':
        case '>':
            return Input::NEXT_LEVEL;
        case ',':
        case '<':
            return Input::PREVIOUS_LEVEL;
        case 27://ESC KEY
        case 'q':
        case 'Q':
            return Input::QUIT;
        default:
            return Input::NONE;
    }
}
