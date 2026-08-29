#pragma once
#pragma once

class Obstacle
{
private:

    float x;

    int y;

    int width;
    int height;

    int type;

public:

    Obstacle(float startX, int obstacleType);

    void move(float speed);

    void draw() const;

    int getX() const;
    int getY() const;

    int getWidth() const;
    int getHeight() const;

    int getType() const;

    bool isOffScreen() const;
};