//
// Created by KacperWojas on 15/08/2026.
//

#ifndef SOKOBAN_CONSOLECONTROLLER_H
#define SOKOBAN_CONSOLECONTROLLER_H

#include "Input.h"

class ConsoleController
{
public:
    static Input GetInput();
    static void init();
    static void exit();
};


#endif //SOKOBAN_CONSOLECONTROLLER_H
