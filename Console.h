#pragma once
#pragma once

class Console
{
public:

    static void clear();

    static void setCursorPosition(
        int x,
        int y
    );

    static void hideCursor();
};