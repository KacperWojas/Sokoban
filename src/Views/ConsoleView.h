//
// Created by KacperWojas on 11/08/2026.
//

#ifndef SOKOBAN_CONSOLEVIEW_H
#define SOKOBAN_CONSOLEVIEW_H

#include <string>
#include <vector>

#include "../Model/Tile.h"

class ConsoleView
{
public:
    static void drawTile(int x, int y, Tile tile);
    static void drawBoard(const std::vector<std::vector<Tile>>& newBoard);
    static void init();
    static void onExit();
private:
    static void putStringAt(int x, int y, const std::string& s);
    static std::string tileToString(Tile tile);
};


#endif //SOKOBAN_CONSOLEVIEW_H
