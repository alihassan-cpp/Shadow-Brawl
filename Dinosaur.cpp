#include "Dinosaur.h"
#include "Console.h"
#include <iostream>

using namespace std;


Dinosaur::Dinosaur()
{
    x = 8;
    y = 20;

    velocityY = 0;

    jumping = false;
}


void Dinosaur::jump()
{
    if (!jumping)
    {
        velocityY = -3.2f;

        jumping = true;
    }
}


void Dinosaur::update()
{
    if (jumping)
    {
        velocityY += 0.55f;

        y += (int)velocityY;


        if (y >= 20)
        {
            y = 20;

            velocityY = 0;

            jumping = false;
        }
    }
}


void Dinosaur::draw() const
{
    Console::setCursorPosition(
        x,
        y
    );

    cout << "D";
}


int Dinosaur::getX() const
{
    return x;
}


int Dinosaur::getY() const
{
    return y;
}


bool Dinosaur::isJumping() const
{
    return jumping;
}


void Dinosaur::reset()
{
    x = 8;
    y = 20;

    velocityY = 0;

    jumping = false;
}