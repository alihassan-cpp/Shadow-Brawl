#pragma once

#include "Dinosaur.h"
#include "Obstacle.h"

#include <vector>

enum class GameState
{
    MENU,
    PLAYING,
    PAUSED,
    GAME_OVER,
    INSTRUCTIONS,
    EXIT
};

class Game
{
private:

    GameState state;

    Dinosaur dinosaur;

    std::vector<Obstacle> obstacles;

    int spawnTimer;
    int spawnDelay;

    int score;
    int highScore;
    int scoreTimer;

    float gameSpeed;


    void handleInput();

    void update();
    void updateScore();
    void updateSpeed();

    void reset();

    void updateObstacles();
    void spawnObstacle();

    bool checkCollision(
        const Dinosaur& dinosaur,
        const Obstacle& obstacle
    );

    bool checkCollisions();


    void loadHighScore();
    void saveHighScore();


    void draw();
    void drawUI();
    void drawGround();

    void showMenu();
    void showInstructions();
    void showPause();
    void showGameOver();


public:

    Game();

    void run();
};