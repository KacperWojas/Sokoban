// #include "Views/ConsoleView.h"
#include "Controlers/ConsoleController.h"
#include <curses.h>
int main()
{
    //region ConsoleView test
    // std::vector<std::vector<Tile>> board;
    // for (int row = 0; row < 5; row++)
    // {
    //     std::vector<Tile> boardRow;
    //     for (int col = 0; col < 5; col++)
    //         boardRow.push_back(Tile::WALL);
    //     board.push_back(boardRow);
    // }
    // ConsoleView::init();
    // ConsoleView::drawBoard(board);
    // ConsoleView::drawTile(1,1,Tile::PLAYER);
    // ConsoleView::onExit();
    //endregion

    //region ConsoleController test
    // ConsoleController::init();
    // printw("test\n");
    // refresh();
    // bool running = true;
    // while (running)
    // {
    //     Input input = ConsoleController::GetInput();
    //     printw("Input: %d\n", static_cast<int>(input));
    //     refresh();
    //
    //     switch (input)
    //     {
    //         case Input::QUIT:
    //             running = false;
    //             break;
    //     }
    // }
    // ConsoleController::exit();
    //endregion

    return 0;
}
