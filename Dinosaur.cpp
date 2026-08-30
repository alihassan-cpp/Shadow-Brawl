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

void Dinosaur::update()
{
    if (jumping)
    {
        y += velocityY;

        velocityY += 1;

        if (y >= 20)
        {
            y = 20;
            velocityY = 0;
            jumping = false;
        }
    }
}

void Dinosaur::jump()
{
    if (!jumping)
    {
        velocityY = -4;
        jumping = true;
    }
}

void Dinosaur::draw() const
{
    Console::setColor(10);

    Console::setCursorPosition(x, y);

    cout << "D";

    Console::setColor(15);
}

void Dinosaur::reset()
{
    x = 8;
    y = 20;

    velocityY = 0;

    jumping = false;
}

int Dinosaur::getX() const
{
    return x;
}

int Dinosaur::getY() const
{
    return y;
}

int Dinosaur::getWidth() const
{
    return 1;
}

int Dinosaur::getHeight() const
{
    return 1;
}

bool Dinosaur::isJumping() const
{
    return jumping;
}