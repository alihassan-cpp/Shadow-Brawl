#pragma once

class Dinosaur
{
private:
    int x;
    int y;
    int velocityY;
    bool jumping;

public:
    Dinosaur();

    void update();
    void jump();
    void draw() const;
    void reset();

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    bool isJumping() const;
};