#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;


Game::Game()
{
    running = true;
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
    dinosaur.update();
}


void Game::draw()
{
    system("cls");

    cout << "========================================" << endl;
    cout << "             SHADOW BRAWL               " << endl;
    cout << "========================================" << endl;

    cout << endl;

    cout << "Dinosaur X: "
        << dinosaur.getX()
        << endl;

    cout << "Dinosaur Y: "
        << dinosaur.getY()
        << endl;

    cout << endl;

    dinosaur.draw();

    cout << endl;

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