#include "Game.h"
#include "Console.h"

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <fstream>

using namespace std;


// ============================================================
// CONSTANTS
// ============================================================

const int SCREEN_WIDTH = 70;
const int GROUND_Y = 20;


// ============================================================
// CONSTRUCTOR
// ============================================================

Game::Game()
{
    state = GameState::MENU;

    spawnTimer = 0;
    spawnDelay = 50;

    score = 0;
    highScore = 0;

    scoreTimer = 0;

    gameSpeed = 1.5f;

    loadHighScore();
}


// ============================================================
// LOAD HIGH SCORE
// ============================================================

void Game::loadHighScore()
{
    ifstream file("highscore.txt");

    if (file.is_open())
    {
        file >> highScore;

        file.close();
    }
    else
    {
        highScore = 0;
    }
}


// ============================================================
// SAVE HIGH SCORE
// ============================================================

void Game::saveHighScore()
{
    ofstream file("highscore.txt");

    if (file.is_open())
    {
        file << highScore;

        file.close();
    }
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


        // Pause

        else if (
            key == 'p' ||
            key == 'P'
            )
        {
            state = GameState::PAUSED;
        }


        // Quit

        else if (
            key == 'q' ||
            key == 'Q'
            )
        {
            state = GameState::EXIT;
        }
    }
}


// ============================================================
// SPAWN OBSTACLE
// ============================================================

void Game::spawnObstacle()
{
    int pattern =
        1 + rand() % 4;


    // Single obstacle

    if (pattern == 1)
    {
        int type =
            1 + rand() % 4;


        obstacles.push_back(
            Obstacle(
                SCREEN_WIDTH - 2,
                type
            )
        );
    }


    // Two small obstacles

    else if (pattern == 2)
    {
        obstacles.push_back(
            Obstacle(
                SCREEN_WIDTH - 2,
                1
            )
        );


        obstacles.push_back(
            Obstacle(
                SCREEN_WIDTH + 2,
                1
            )
        );
    }


    // Wide obstacle

    else if (pattern == 3)
    {
        obstacles.push_back(
            Obstacle(
                SCREEN_WIDTH - 2,
                3
            )
        );
    }


    // Flying obstacle

    else
    {
        obstacles.push_back(
            Obstacle(
                SCREEN_WIDTH - 2,
                6
            )
        );
    }


    // Spawn timing

    int minimumDelay =
        40 - (int)(gameSpeed * 4);


    int maximumDelay =
        60 - (int)(gameSpeed * 5);


    if (minimumDelay < 25)
    {
        minimumDelay = 25;
    }


    if (maximumDelay < 35)
    {
        maximumDelay = 35;
    }


    spawnDelay =
        minimumDelay +
        rand() %
        (maximumDelay - minimumDelay + 1);


    spawnTimer = spawnDelay;
}


// ============================================================
// UPDATE OBSTACLES
// ============================================================

void Game::updateObstacles()
{
    for (
        Obstacle& obstacle :
        obstacles
        )
    {
        obstacle.move(gameSpeed);
    }


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


// ============================================================
// SCORE
// ============================================================

void Game::updateScore()
{
    scoreTimer++;


    // Approximately every 0.25 seconds

    if (scoreTimer >= 4)
    {
        score++;

        scoreTimer = 0;
    }


    if (score > highScore)
    {
        highScore = score;
    }
}


// ============================================================
// SPEED
// ============================================================

void Game::updateSpeed()
{
    gameSpeed =
        1.5f +
        (score / 25) * 0.2f;


    if (gameSpeed > 2.8f)
    {
        gameSpeed = 2.8f;
    }
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


    updateScore();

    updateSpeed();

    updateObstacles();


    if (checkCollisions())
    {
        state = GameState::GAME_OVER;

        saveHighScore();
    }
}


// ============================================================
// COLLISION
// ============================================================

bool Game::checkCollision(
    const Dinosaur& dinosaur,
    const Obstacle& obstacle
)
{
    int dinosaurLeft =
        dinosaur.getX();


    int dinosaurRight =
        dinosaur.getX() +
        dinosaur.getWidth() -
        1;


    int dinosaurTop =
        dinosaur.getY() -
        dinosaur.getHeight() +
        1;


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


    bool horizontalCollision =
        dinosaurRight >= obstacleLeft &&
        dinosaurLeft <= obstacleRight;


    bool verticalCollision =
        dinosaurBottom >= obstacleTop &&
        dinosaurTop <= obstacleBottom;


    return
        horizontalCollision &&
        verticalCollision;
}


// ============================================================
// CHECK ALL COLLISIONS
// ============================================================

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
// RESET
// ============================================================

void Game::reset()
{
    dinosaur.reset();

    obstacles.clear();

    spawnTimer = 0;

    spawnDelay = 50;

    score = 0;

    scoreTimer = 0;

    gameSpeed = 1.5f;

    state = GameState::PLAYING;
}


// ============================================================
// START COUNTDOWN
// ============================================================

void Game::startCountdown()
{
    Console::clear();


    for (int number = 3; number >= 1; number--)
    {
        Console::clear();


        Console::setColor(14);

        Console::setCursorPosition(
            34,
            8
        );

        cout << number;


        Console::setColor(15);

        Sleep(1000);
    }


    Console::clear();


    Console::setColor(10);

    Console::setCursorPosition(
        33,
        8
    );

    cout << "GO!";


    Console::setColor(15);

    Sleep(500);
}


// ============================================================
// DRAW UI
// ============================================================

void Game::drawUI()
{
    Console::setColor(13);

    Console::setCursorPosition(
        0,
        0
    );

    cout <<
        "======================================================================";


    Console::setColor(10);

    Console::setCursorPosition(
        2,
        1
    );

    cout <<
        "SHADOW BRAWL";


    Console::setColor(10);

    Console::setCursorPosition(
        25,
        1
    );

    cout <<
        "SCORE: "
        << score;


    Console::setColor(14);

    Console::setCursorPosition(
        45,
        1
    );

    cout <<
        "HIGH SCORE: "
        << highScore;


    Console::setColor(13);

    Console::setCursorPosition(
        0,
        3
    );

    cout <<
        "======================================================================";


    Console::setColor(15);
}


// ============================================================
// GROUND
// ============================================================

void Game::drawGround()
{
    Console::setColor(10);

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


    Console::setColor(15);
}


// ============================================================
// DRAW
// ============================================================

void Game::draw()
{
    Console::clear();


    drawUI();

    drawGround();


    dinosaur.draw();


    for (
        const Obstacle& obstacle :
        obstacles
        )
    {
        obstacle.draw();
    }


    Console::setColor(15);

    cout.flush();
}


// ============================================================
// MENU
// ============================================================

void Game::showMenu()
{
    Console::clear();


    Console::setColor(13);

    Console::setCursorPosition(
        15,
        3
    );

    cout <<
        "========================================";


    Console::setColor(10);

    Console::setCursorPosition(
        27,
        5
    );

    cout <<
        "SHADOW BRAWL";


    Console::setColor(13);

    Console::setCursorPosition(
        15,
        7
    );

    cout <<
        "========================================";


    Console::setColor(11);

    Console::setCursorPosition(
        28,
        10
    );

    cout <<
        "1. PLAY";


    Console::setColor(14);

    Console::setCursorPosition(
        25,
        12
    );

    cout <<
        "2. INSTRUCTIONS";


    Console::setColor(12);

    Console::setCursorPosition(
        28,
        14
    );

    cout <<
        "3. EXIT";


    Console::setColor(15);


    while (
        state == GameState::MENU
        )
    {
        char key = _getch();


        if (key == '1')
        {
            reset();

            startCountdown();

            break;
        }


        if (key == '2')
        {
            state = GameState::INSTRUCTIONS;

            break;
        }


        if (key == '3')
        {
            state = GameState::EXIT;

            break;
        }
    }
}


// ============================================================
// INSTRUCTIONS
// ============================================================

void Game::showInstructions()
{
    Console::clear();


    Console::setColor(11);

    Console::setCursorPosition(
        25,
        4
    );

    cout <<
        "HOW TO PLAY";


    Console::setColor(15);

    Console::setCursorPosition(
        20,
        7
    );

    cout <<
        "SPACE / W = JUMP";


    Console::setCursorPosition(
        20,
        9
    );

    cout <<
        "AVOID THE OBSTACLES";


    Console::setCursorPosition(
        20,
        11
    );

    cout <<
        "SURVIVE AS LONG AS POSSIBLE";


    Console::setCursorPosition(
        20,
        13
    );

    cout <<
        "P = PAUSE";


    Console::setCursorPosition(
        20,
        14
    );

    cout <<
        "Q = QUIT";


    Console::setColor(14);

    Console::setCursorPosition(
        20,
        17
    );

    cout <<
        "Press B to go back";


    Console::setColor(15);


    while (
        state == GameState::INSTRUCTIONS
        )
    {
        char key = _getch();


        if (
            key == 'b' ||
            key == 'B'
            )
        {
            state = GameState::MENU;
        }
    }
}


// ============================================================
// PAUSE
// ============================================================

void Game::showPause()
{
    Console::clear();


    Console::setColor(14);

    Console::setCursorPosition(
        28,
        6
    );

    cout <<
        "====================";


    Console::setColor(11);

    Console::setCursorPosition(
        34,
        8
    );

    cout <<
        "PAUSED";


    Console::setColor(14);

    Console::setCursorPosition(
        28,
        10
    );

    cout <<
        "====================";


    Console::setColor(10);

    Console::setCursorPosition(
        25,
        13
    );

    cout <<
        "P - RESUME";


    Console::setColor(12);

    Console::setCursorPosition(
        25,
        15
    );

    cout <<
        "Q - QUIT";


    Console::setColor(15);


    while (
        state == GameState::PAUSED
        )
    {
        char key = _getch();


        if (
            key == 'p' ||
            key == 'P'
            )
        {
            state = GameState::PLAYING;
        }


        else if (
            key == 'q' ||
            key == 'Q'
            )
        {
            state = GameState::EXIT;
        }
    }
}


// ============================================================
// GAME OVER
// ============================================================

void Game::showGameOver()
{
    Console::clear();


    Console::setColor(13);

    Console::setCursorPosition(
        20,
        7
    );

    cout <<
        "==============================";


    Console::setColor(12);

    Console::setCursorPosition(
        28,
        8
    );

    cout <<
        "GAME OVER";


    Console::setColor(13);

    Console::setCursorPosition(
        20,
        9
    );

    cout <<
        "==============================";


    Console::setColor(10);

    Console::setCursorPosition(
        27,
        11
    );

    cout <<
        "SCORE: "
        << score;


    Console::setColor(14);

    Console::setCursorPosition(
        25,
        12
    );

    cout <<
        "HIGH SCORE: "
        << highScore;


    Console::setColor(11);

    Console::setCursorPosition(
        22,
        15
    );

    cout <<
        "R - RETURN TO MENU";


    Console::setColor(12);

    Console::setCursorPosition(
        22,
        16
    );

    cout <<
        "Q - QUIT";


    Console::setColor(15);


    while (true)
    {
        char key = _getch();


        if (
            key == 'q' ||
            key == 'Q'
            )
        {
            state = GameState::EXIT;

            break;
        }


        if (
            key == 'r' ||
            key == 'R'
            )
        {
            state = GameState::MENU;

            break;
        }
    }
}


// ============================================================
// MAIN GAME LOOP
// ============================================================

void Game::run()
{
    Console::hideCursor();


    while (
        state != GameState::EXIT
        )
    {
        if (
            state == GameState::MENU
            )
        {
            showMenu();
        }


        else if (
            state == GameState::PLAYING
            )
        {
            while (
                state == GameState::PLAYING
                )
            {
                handleInput();

                update();

                draw();

                Sleep(60);
            }
        }


        else if (
            state == GameState::PAUSED
            )
        {
            showPause();
        }


        else if (
            state == GameState::GAME_OVER
            )
        {
            showGameOver();
        }


        else if (
            state == GameState::INSTRUCTIONS
            )
        {
            showInstructions();
        }
    }
}