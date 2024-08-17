#define GRAPHOBJECT_H
#include "Gameconstants.h"

class GraphObject {
public:
     

    GraphObject(int imageID, int startX, int startY, Direction startDirection, double size = 1.0, unsigned int depth = 0);

    
    virtual ~GraphObject() {}

    
    void setVisible(bool shouldIDisplay);

    
    int getX() const;

    
    int getY() const;

    
    void moveTo(int x, int y);

    
    Direction getDirection() const;

    
    void setDirection(Direction d);

private:
    int m_imageID;         
    int m_x, m_y;          
    Direction m_direction; 
    double m_size;         
    unsigned int m_depth;  
    bool m_visible;        
};
