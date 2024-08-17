#include "Actor.h"
#include "StudentWorld.h"

Actor::Actor(int imageID, int startX, int startY, Direction startDir, double size, unsigned int depth, StudentWorld* world)
    : GraphObject(imageID, startX, startY, startDir, size, depth), m_alive(true), m_world(world) {
    setVisible(true);
}

Actor::~Actor() {}

bool Actor::isAlive() const {
    return m_alive;
}

void Actor::setDead() {
    m_alive = false;
}

StudentWorld* Actor::getWorld() const {
    return m_world;
}

// Implementation of Earth class
Earth::Earth(int startX, int startY, StudentWorld* world)
    : Actor(TID_EARTH, startX, startY, right, 0.25, 3, world) {
}

Earth::~Earth() {}

virtual void Earth::doSomething() {
    // Earth objects do not do anything in each tick, so this can be left empty
}

// Implementation of TunnelMan class
TunnelMan::TunnelMan(int startX, int startY, StudentWorld* world)
    : Actor(TID_PLAYER, startX, startY, right, 1.0, 0, world), m_hitPoints(10), m_water(5), m_sonar(1), m_gold(0) {
}

TunnelMan::~TunnelMan() {}

void TunnelMan::doSomething() {
    int key;
    if (getWorld()->getKey(key)) {
        switch (key) {
            case KEY_PRESS_LEFT:
                if (getX() > 0) moveTo(getX() - 1, getY());
                break;
            case KEY_PRESS_RIGHT:
                if (getX() < VIEW_WIDTH - 4) moveTo(getX() + 1, getY());
                break;
            case KEY_PRESS_UP:
                if (getY() < VIEW_HEIGHT - 4) moveTo(getX(), getY() + 1);
                break;
            case KEY_PRESS_DOWN:
                if (getY() > 0) moveTo(getX(), getY() - 1);
                break;
        }
    }
}
