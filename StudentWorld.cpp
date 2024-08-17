#include "Actor.h"
#include <vector>
#include <string>


class Actor; 
class Earth;    
class TunnelMan; 

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir = "assets/")
        : GameWorld(assetDir) {
        init();
    }

    virtual int init() override;
    virtual int move() override;
    virtual void cleanUp() override;

private:
    std::vector<Actor*> m_actors; 
    Earth* m_earth[64][60];       
    TunnelMan* m_tunnelMan;       

    void addNewActors(); 
    void removeDeadActors(); 
};

int StudentWorld::init()
{
    // Initialize the Earth objects
    for (int x = 0; x < 64; x++) {
        for (int y = 0; y < 60; y++) {
            m_earth[x][y] = new Earth(x, y);
        }
    }

    // Create the TunnelMan object
    m_tunnelMan = new TunnelMan();

    // Populate the oil field with Boulders, Barrels of Oil, and Gold Nuggets
    // The specific placement logic will depend on your game's requirements

    // temp status
    return 1;
}

int StudentWorld::move()
{
    // Ask each actor to do something
    for (Actor* actor : m_actors) {
        if (actor->isAlive()) {
            actor->doSomething();
        }
    }

    // Remove any dead actors
    removeDeadActors();

    // Add new actors as required by the game logic
    addNewActors();

    // Check game over conditions and update the game state accordingly
    if (/* condition to end game */) {
        return GWSTATUS_PLAYER_DIED;
    }

    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
    // Delete all actors
    for (Actor* actor : m_actors) {
        delete actor;
    }
    m_actors.clear();

    // Delete TunnelMan
    delete m_tunnelMan;
    m_tunnelMan = nullptr;

    // Delete all Earth objects
    for (int x = 0; x < 64; x++) {
        for (int y = 0; y < 60; y++) {
            delete m_earth[x][y];
        }
    }
}

void StudentWorld::addNewActors()
{
    // Logic to add new actors based on game rules and random events
}

void StudentWorld::removeDeadActors()
{
    m_actors.erase(std::remove_if(m_actors.begin(), m_actors.end(),
                                  [](Actor* actor) { return !actor->isAlive(); }),
                   m_actors.end());
}