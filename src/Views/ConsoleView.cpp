//
// Created by KacperWojas on 11/08/2026.
//

#include "ConsoleView.h"
#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
void ConsoleView::init()
{
    std::cout << "\033[?1049h";
    #ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD mode = 0;
    GetConsoleMode(hOut, &mode);

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, mode);
    #endif
}

void ConsoleView::onExit()
{
    std::cin >> std::ws;
    std::cout << "\033[?1049l";
}

void ConsoleView::putStringAt(const int x, const int y, const std::string& s)
{
    std::cout << "\033[" << y << ";" << x << "H" << s;
}

void ConsoleView::drawTile(const int x, const int y, const Tile tile)
{
    putStringAt(x*2+1, y+1, tileToString(tile));
}

std::string ConsoleView::tileToString(const Tile tile)
{
    switch (tile)
    {
    case Tile::EMPTY:
        return "  ";
    case Tile::WALL:
        return "##";
    case Tile::GOAL:
        return "..";
    case Tile::PLAYER:
        return ":)";
    case Tile::PLAYER_ON_GOAL:
        return ":D";
    case Tile::BOX:
        return "[]";
    case Tile::BOX_ON_GOAL:
        return "{}";
    default:
        return "Er";
    }
}

void ConsoleView::drawBoard(const std::vector<std::vector<Tile>>& newBoard)
{
    std::cout << "\033[2J";//ansi sequence clearing console
    std::cout << "\033[H";// ansi sequence resetting cursor
    std::string stringBoard;
    for (const std::vector<Tile> & row : newBoard)
    {
        for (const Tile cell : row)
            stringBoard += tileToString(cell);
        stringBoard += "\n";
    }
    std::cout << stringBoard;
}
