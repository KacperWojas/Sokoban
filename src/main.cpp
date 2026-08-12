#include "Views/ConsoleView.h"

int main()
{
    std::vector<std::vector<Tile>> board;
    for (int row = 0; row < 5; row++)
    {
        std::vector<Tile> boardRow;
        for (int col = 0; col < 5; col++)
            boardRow.push_back(Tile::WALL);
        board.push_back(boardRow);
    }
    ConsoleView::init();
    ConsoleView::drawBoard(board);
    ConsoleView::drawTile(1,1,Tile::PLAYER);
    ConsoleView::onExit();

    return 0;
}
