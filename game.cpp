#include "Game.h"
#include <iostream>
using namespace std;
Game::Game()
{
    running = true;
}
void Game::run()
{
    cout << "========================================" << endl;
    cout << "             SHADOW BRAWL               " << endl;
    cout << "========================================" << endl;

    cout << endl;
    cout << "Game is starting..." << endl;
}