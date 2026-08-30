#pragma once

#include "Dinosaur.h"
#include "Obstacle.h"

#include <vector>


enum class GameState
{
    PLAYING,
    GAME_OVER,
    EXIT
};


class Game
{
private:
    float gameSpeed;
    int scoreTimer;
    int score;
    int highScore;
    GameState state;

    Dinosaur dinosaur;

    std::vector<Obstacle> obstacles;

    int spawnTimer;

    int spawnDelay;


    void handleInput();

    void updateScore();

    void updateSpeed();

    void update();

    void reset();

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

    void showGameOver();


public:

    Game();

    void run();
};