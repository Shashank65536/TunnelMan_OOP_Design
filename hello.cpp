#include <iostream>
#include <vector>
#include <string>
#include "Actor.h"
#include "StudentWorld.h"
// #include "Gameconstants.h"
using namespace std;

int main()
{
    Direction d = Direction::right;
    StudentWorld world("hello");
    cout<<"hello world"<<endl;

    Actor actor(1, 50, 100, d, 1.0, 0, &world);

        if (actor.isAlive()) {
        std::cout << "The hero is alive and ready to act!" << std::endl;
    }
}