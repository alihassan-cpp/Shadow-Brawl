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

    int spawnTimer;

    int spawnDelay;


    void handleInput();

    void update();

    void updateObstacles();

    void spawnObstacle();


    bool checkCollision(
        const Dinosaur& dinosaur,
        const Obstacle& obstacle
    );

    bool checkCollisions();


    void draw();

    void drawUI();

    void drawGround();


public:

    Game();

    void run();
};