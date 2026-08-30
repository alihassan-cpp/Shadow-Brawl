#include "Game.h"
#include "Console.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;


Game::Game()
{
    running = true;

    // Temporary test obstacle
    obstacles.push_back(
        Obstacle(60, 1)
    );
}


void Game::handleInput()
{
    if (_kbhit())
    {
        char key = _getch();

        if (
            key == ' ' ||
            key == 'w' ||
            key == 'W'
            )
        {
            dinosaur.jump();
        }

        else if (
            key == 'q' ||
            key == 'Q'
            )
        {
            running = false;
        }
    }
}


void Game::update()
{
    // Update dinosaur
    dinosaur.update();


    // Move all obstacles

    for (
        Obstacle& obstacle :
        obstacles
        )
    {
        obstacle.move(1.5f);
    }
}


void Game::draw()
{
    Console::clear();


    // Draw dinosaur

    dinosaur.draw();


    // Draw obstacles

    for (
        const Obstacle& obstacle :
        obstacles
        )
    {
        obstacle.draw();
    }


    cout.flush();
}
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