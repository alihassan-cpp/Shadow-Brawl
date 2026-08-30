#include "Dinosaur.h"
#include "Console.h"
#include <iostream>

using namespace std;

const int GROUND_Y = 20;


// ============================================================
// CONSTRUCTOR
// ============================================================

Dinosaur::Dinosaur()
{
    x = 8;
    y = GROUND_Y;

    velocityY = 0;

    jumping = false;
}


// ============================================================
// UPDATE
// ============================================================

void Dinosaur::update()
{
    if (jumping)
    {
        // Apply vertical movement
        y += velocityY;

        // Gravity
        velocityY += 1;


        // Landing
        if (y >= GROUND_Y)
        {
            y = GROUND_Y;

            velocityY = 0;

            jumping = false;
        }
    }
}


// ============================================================
// JUMP
// ============================================================

void Dinosaur::jump()
{
    if (!jumping)
    {
        // Bigger jump
        velocityY = -5;

        jumping = true;
    }
}


// ============================================================
// DRAW
// ============================================================

void Dinosaur::draw() const
{
    Console::setColor(10);

    Console::setCursorPosition(
        x,
        y
    );

    cout << "D";

    Console::setColor(15);
}


// ============================================================
// RESET
// ============================================================

void Dinosaur::reset()
{
    x = 8;
    y = GROUND_Y;

    velocityY = 0;

    jumping = false;
}


// ============================================================
// GET X
// ============================================================

int Dinosaur::getX() const
{
    return x;
}


// ============================================================
// GET Y
// ============================================================

int Dinosaur::getY() const
{
    return y;
}


// ============================================================
// GET WIDTH
// ============================================================

int Dinosaur::getWidth() const
{
    return 1;
}


// ============================================================
// GET HEIGHT
// ============================================================

int Dinosaur::getHeight() const
{
    return 1;
}


// ============================================================
// IS JUMPING
// ============================================================

bool Dinosaur::isJumping() const
{
    return jumping;
}