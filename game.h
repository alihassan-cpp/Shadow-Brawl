#pragma once

#include "Dinosaur.h"

class Game
{
private:

    bool running;

    Dinosaur dinosaur;

    void handleInput();
    void update();
    void draw();

public:

    Game();

    void run();
};