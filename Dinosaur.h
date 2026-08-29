#pragma once
#pragma once

class Dinosaur
{
private:

    int x;
    int y;

    float velocityY;

    bool jumping;

public:

    Dinosaur();

    void jump();

    void update();

    void draw() const;

    int getX() const;
    int getY() const;

    bool isJumping() const;

    void reset();
};