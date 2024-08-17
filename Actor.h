#define ACTOR_H

#include "GraphObject.h"
#include "StudentWorld.h"
// #include "Gameconstants.h"
const int TID_PLAYER = 0;
const int TID_EARTH = 1;

class StudentWorld;

class Actor : public GraphObject {
public:
    Actor(int imageID, int startX, int startY, Direction startDir, double size, unsigned int depth, StudentWorld* world);
    virtual ~Actor();

    // virtual void doSomething() = 0;
    bool isAlive() const;
    void setDead();
    StudentWorld* getWorld() const;

private:
    bool m_alive;
    StudentWorld* m_world;
};

class Earth : public Actor {
public:
    Earth(int startX, int startY, StudentWorld* world);
    virtual ~Earth();

    virtual void doSomething();
};

class TunnelMan : public Actor {
public:
    TunnelMan(int startX, int startY, StudentWorld* world);
    virtual ~TunnelMan();

    virtual void doSomething();

private:
    int m_hitPoints;
    int m_water;
    int m_sonar;
    int m_gold;
};


