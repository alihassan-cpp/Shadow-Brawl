#include "Obstacle.h"
#include "Console.h"

#include <iostream>

using namespace std;


const int GROUND_Y = 20;


// ============================================================
// CONSTRUCTOR
// ============================================================

Obstacle::Obstacle(
    float startX,
    int obstacleType
)
{
    x = startX;

    type = obstacleType;


    // --------------------------------------------------------
    // Small cactus
    // --------------------------------------------------------

    if (type == 1)
    {
        width = 1;
        height = 2;

        y = GROUND_Y;
    }


    // --------------------------------------------------------
    // Medium cactus
    // --------------------------------------------------------

    else if (type == 2)
    {
        width = 2;
        height = 3;

        y = GROUND_Y;
    }


    // --------------------------------------------------------
    // Wide cactus
    // --------------------------------------------------------

    else if (type == 3)
    {
        width = 4;
        height = 2;

        y = GROUND_Y;
    }


    // --------------------------------------------------------
    // Tall cactus
    // --------------------------------------------------------

    else if (type == 4)
    {
        width = 2;
        height = 4;

        y = GROUND_Y;
    }


    // --------------------------------------------------------
    // Large block
    // --------------------------------------------------------

    else if (type == 5)
    {
        width = 4;
        height = 2;

        y = GROUND_Y;
    }


    // --------------------------------------------------------
    // Flying obstacle
    // --------------------------------------------------------

    else
    {
        width = 3;
        height = 2;

        y = GROUND_Y - 4;
    }
}


// ============================================================
// MOVE
// ============================================================

void Obstacle::move(float speed)
{
    x -= speed;
}


// ============================================================
// DRAW
// ============================================================

void Obstacle::draw() const
{
    int drawX = (int)x;


    // --------------------------------------------------------
    // Small cactus
    // --------------------------------------------------------

    if (type == 1)
    {
        Console::setColor(15);

        Console::setCursorPosition(
            drawX,
            y
        );

        cout << "#";


        Console::setCursorPosition(
            drawX,
            y - 1
        );

        cout << "#";
    }


    // --------------------------------------------------------
    // Medium cactus
    // --------------------------------------------------------

    else if (type == 2)
    {
        Console::setColor(15);

        Console::setCursorPosition(
            drawX,
            y
        );

        cout << "##";


        Console::setCursorPosition(
            drawX,
            y - 1
        );

        cout << "##";


        Console::setCursorPosition(
            drawX,
            y - 2
        );

        cout << "##";
    }


    // --------------------------------------------------------
    // Wide cactus
    // --------------------------------------------------------

    else if (type == 3)
    {
        Console::setColor(15);

        Console::setCursorPosition(
            drawX,
            y
        );

        cout << "####";


        Console::setCursorPosition(
            drawX,
            y - 1
        );

        cout << "####";
    }


    // --------------------------------------------------------
    // Tall cactus
    // --------------------------------------------------------

    else if (type == 4)
    {
        Console::setColor(15);

        Console::setCursorPosition(
            drawX,
            y
        );

        cout << "##";


        Console::setCursorPosition(
            drawX,
            y - 1
        );

        cout << "##";


        Console::setCursorPosition(
            drawX,
            y - 2
        );

        cout << "##";


        Console::setCursorPosition(
            drawX,
            y - 3
        );

        cout << "##";
    }


    // --------------------------------------------------------
    // Large block
    // --------------------------------------------------------

    else if (type == 5)
    {
        Console::setColor(15);

        Console::setCursorPosition(
            drawX,
            y
        );

        cout << "####";


        Console::setCursorPosition(
            drawX,
            y - 1
        );

        cout << "####";
    }


    // --------------------------------------------------------
    // Flying obstacle
    // --------------------------------------------------------

    else
    {
        Console::setColor(14);

        Console::setCursorPosition(
            drawX + 1,
            y
        );

        cout << "T";


        Console::setCursorPosition(
            drawX,
            y - 1
        );

        cout << "TTT";
    }


    Console::setColor(15);
}


// ============================================================
// GETTERS
// ============================================================

int Obstacle::getX() const
{
    return (int)x;
}


int Obstacle::getY() const
{
    return y;
}


int Obstacle::getWidth() const
{
    return width;
}


int Obstacle::getHeight() const
{
    return height;
}


int Obstacle::getType() const
{
    return type;
}


// ============================================================
// OFF SCREEN
// ============================================================

bool Obstacle::isOffScreen() const
{
    return x + width < 0;
}