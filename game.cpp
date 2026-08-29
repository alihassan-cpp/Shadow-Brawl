#include "Game.h"
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
    system("cls");


    cout << "========================================"
        << endl;

    cout << "             SHADOW BRAWL"
        << endl;

    cout << "========================================"
        << endl;


    cout << endl;


    // Draw dinosaur

    dinosaur.draw();


    cout << endl;


    // Draw obstacles

    for (
        const Obstacle& obstacle :
        obstacles
        )
    {
        cout << "Obstacle at X: "
            << obstacle.getX()
            << endl;

        cout << "Obstacle: ";

        obstacle.draw();

        cout << endl;
    }


    cout << endl;

    cout << "SPACE / W = Jump" << endl;

    cout << "Q = Quit" << endl;
}


void Game::run()
{
    while (running)
    {
        handleInput();

        update();

        draw();

        Sleep(60);
    }
}