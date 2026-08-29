#include <iostream>
#include "Obstacle.h"

using namespace std;


int main()
{
    Obstacle obstacle(
        70,
        3
    );


    cout << "Obstacle created!" << endl;

    cout << "X: "
        << obstacle.getX()
        << endl;

    cout << "Y: "
        << obstacle.getY()
        << endl;

    cout << "Width: "
        << obstacle.getWidth()
        << endl;

    cout << "Height: "
        << obstacle.getHeight()
        << endl;

    cout << "Type: "
        << obstacle.getType()
        << endl;


    cout << endl;

    cout << "Obstacle: ";

    obstacle.draw();

    cout << endl;


    return 0;
}