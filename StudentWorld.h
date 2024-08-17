#ifndef STUDENTWORLD_H

#define STUDENTWORLD_H

#include "GameWorld.h"
#include <vector>
#include <string>

// Forward declarations for other classes used as types in StudentWorld
class Actor;
class Earth;
class TunnelMan;

class StudentWorld : public GameWorld
{
public:
    
    explicit StudentWorld(std::string assetDir);

    
    virtual ~StudentWorld();

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
#endif