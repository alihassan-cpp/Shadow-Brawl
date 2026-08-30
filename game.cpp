#include "Game.h"
#include "Console.h"

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>


using namespace std;


// ============================================================
// GAME CONSTANTS
// ============================================================

const int SCREEN_WIDTH = 70;

const int GROUND_Y = 20;


// ============================================================
// COLORS
// ============================================================

const int GREEN = 10;
const int CYAN = 11;
const int RED = 12;
const int MAGENTA = 13;
const int YELLOW = 14;
const int WHITE = 15;


// ============================================================
// CONSTRUCTOR
// ============================================================

Game::Game()
{
    running = true;

    spawnTimer = 0;

    spawnDelay = 50;
}


// ============================================================
// INPUT
// ============================================================

void Game::handleInput()
{
    if (_kbhit())
    {
        char key = _getch();


        // Jump

        if (
            key == ' ' ||
            key == 'w' ||
            key == 'W'
            )
        {
            dinosaur.jump();
        }


        // Quit

        else if (
            key == 'q' ||
            key == 'Q'
            )
        {
            running = false;
        }
    }
}


// ============================================================
// SPAWN OBSTACLE
// ============================================================

void Game::spawnObstacle()
{
    int obstacleType;

    obstacleType = 1 + rand() % 6;


    obstacles.push_back(
        Obstacle(
            SCREEN_WIDTH - 2,
            obstacleType
        )
    );


    // Random delay before next obstacle

    spawnDelay =
        35 + rand() % 30;


    spawnTimer = spawnDelay;
}


// ============================================================
// UPDATE OBSTACLES
// ============================================================

void Game::updateObstacles()
{
    // Move obstacles

    for (
        Obstacle& obstacle :
        obstacles
        )
    {
        obstacle.move(1.5f);
    }


    // Remove obstacles
    // that have left the screen

    for (
        int i = 0;
        i < (int)obstacles.size();
        i++
        )
    {
        if (
            obstacles[i].isOffScreen()
            )
        {
            obstacles.erase(
                obstacles.begin() + i
            );

            i--;
        }
    }
}

bool Game::checkCollision(
    const Dinosaur& dinosaur,
    const Obstacle& obstacle
)
{
    int dinosaurLeft =
        dinosaur.getX();

    int dinosaurRight =
        dinosaur.getX() +
        1;


    int dinosaurTop =
        dinosaur.getY();

    int dinosaurBottom =
        dinosaur.getY();


    int obstacleLeft =
        obstacle.getX();

    int obstacleRight =
        obstacle.getX() +
        obstacle.getWidth() -
        1;


    int obstacleTop =
        obstacle.getY() -
        obstacle.getHeight() +
        1;

    int obstacleBottom =
        obstacle.getY();


    // Horizontal overlap

    bool horizontalCollision =
        dinosaurRight >= obstacleLeft &&
        dinosaurLeft <= obstacleRight;


    // Vertical overlap

    bool verticalCollision =
        dinosaurBottom >= obstacleTop &&
        dinosaurTop <= obstacleBottom;


    return horizontalCollision &&
        verticalCollision;
}
bool Game::checkCollisions()
{
    for (
        const Obstacle& obstacle :
        obstacles
        )
    {
        if (
            checkCollision(
                dinosaur,
                obstacle
            )
            )
        {
            return true;
        }
    }


    return false;
}
// ============================================================
// UPDATE
// ============================================================

void Game::update()
{
    dinosaur.update();


    spawnTimer--;


    if (spawnTimer <= 0)
    {
        spawnObstacle();
    }


    updateObstacles();


    if (checkCollisions())
    {
        running = false;
    }
}


// ============================================================
// DRAW UI
// ============================================================

void Game::drawUI()
{
    // Top border

    Console::setColor(MAGENTA);

    Console::setCursorPosition(
        0,
        0
    );

    cout <<
        "======================================================================";


    // Title

    Console::setColor(GREEN);

    Console::setCursorPosition(
        2,
        1
    );

    cout <<
        "SHADOW BRAWL";


    // Score

    Console::setColor(GREEN);

    Console::setCursorPosition(
        25,
        1
    );

    cout <<
        "SCORE: 0";


    // High score

    Console::setColor(YELLOW);

    Console::setCursorPosition(
        45,
        1
    );

    cout <<
        "HIGH SCORE: 0";


    // Bottom UI border

    Console::setColor(MAGENTA);

    Console::setCursorPosition(
        0,
        3
    );

    cout <<
        "======================================================================";


    Console::setColor(WHITE);
}


// ============================================================
// DRAW GROUND
// ============================================================

void Game::drawGround()
{
    Console::setColor(GREEN);


    Console::setCursorPosition(
        0,
        GROUND_Y + 1
    );


    for (
        int i = 0;
        i < SCREEN_WIDTH;
        i++
        )
    {
        cout << "-";
    }


    Console::setColor(WHITE);
}


// ============================================================
// DRAW
// ============================================================

void Game::draw()
{
    Console::clear();


    // Draw UI

    drawUI();


    // Draw ground

    drawGround();


    // Draw dinosaur

    dinosaur.draw();


    // Draw all obstacles

    for (
        const Obstacle& obstacle :
        obstacles
        )
    {
        obstacle.draw();
    }


    Console::setColor(WHITE);


    cout.flush();
}


// ============================================================
// RUN
// ============================================================

void Game::run()
{
    Console::hideCursor();


    while (running)
    {
        handleInput();

        update();

        draw();

        Sleep(60);
    }
}