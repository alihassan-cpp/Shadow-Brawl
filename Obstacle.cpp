#include "Obstacle.h"
#include <iostream>

using namespace std;


const int GROUND_Y = 20;


Obstacle::Obstacle(
    float startX,
    int obstacleType
)
{
    x = startX;

    type = obstacleType;


    // Small cactus
    if (type == 1)
    {
        width = 1;
        height = 2;

        y = GROUND_Y;
    }


    // Medium cactus
    else if (type == 2)
    {
        width = 2;
        height = 3;

        y = GROUND_Y;
    }


    // Wide cactus
    else if (type == 3)
    {
        width = 4;
        height = 2;

        y = GROUND_Y;
    }


    // Tall cactus
    else if (type == 4)
    {
        width = 2;
        height = 4;

        y = GROUND_Y;
    }


    // Large block
    else if (type == 5)
    {
        width = 4;
        height = 2;

        y = GROUND_Y;
    }


    // Flying obstacle
    else
    {
        width = 3;
        height = 2;

        y = GROUND_Y - 4;
    }
}


void Obstacle::move(float speed)
{
    x -= speed;
}


void Obstacle::draw() const
{
    int drawX = (int)x;


    // Small cactus
    if (type == 1)
    {
        cout << "#";
    }


    // Medium cactus
    else if (type == 2)
    {
        cout << "##";
    }


    // Wide cactus
    else if (type == 3)
    {
        cout << "####";
    }


    // Tall cactus
    else if (type == 4)
    {
        cout << "##";
    }


    // Large block
    else if (type == 5)
    {
        cout << "####";
    }


    // Flying obstacle
    else
    {
        cout << "T";
    }
}


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


bool Obstacle::isOffScreen() const
{
    return x + width < 0;
}