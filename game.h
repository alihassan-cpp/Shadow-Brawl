#pragma once

#include "Dinosaur.h"
#include "Obstacle.h"
#include <vector>

class Game
{
private:

    bool running;

    Dinosaur dinosaur;

    std::vector<Obstacle> obstacles;

    void handleInput();
    void update();
    void draw();

public:

    Game();

    void run();
};