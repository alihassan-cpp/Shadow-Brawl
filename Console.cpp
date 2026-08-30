#include "Console.h"
#include <windows.h>
#include <cstdlib>


void Console::clear()
{
    system("cls");
}


void Console::setCursorPosition(
    int x,
    int y
)
{
    COORD position;

    position.X = x;
    position.Y = y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        position
    );
}


void Console::hideCursor()
{
    HANDLE consoleHandle =
        GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO info;

    info.dwSize = 1;

    info.bVisible = false;

    SetConsoleCursorInfo(
        consoleHandle,
        &info
    );
}