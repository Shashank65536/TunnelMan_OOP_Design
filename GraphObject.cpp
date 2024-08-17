#include "GraphObject.h"
// #include "Gameconstants.h"
GraphObject::GraphObject(int imageID, int startX, int startY, Direction startDirection, double size, unsigned int depth)
    : m_imageID(imageID), m_x(startX), m_y(startY), m_direction(startDirection), m_size(size), m_depth(depth), m_visible(false) {
}

// Set the visibility of the object
void GraphObject::setVisible(bool shouldIDisplay) {
    m_visible = shouldIDisplay;
}

// Get the current X position
int GraphObject::getX() const {
    return m_x;
}

// Get the current Y position
int GraphObject::getY() const {
    return m_y;
}

// Move the object to a new X, Y position
void GraphObject::moveTo(int x, int y) {
    m_x = x;
    m_y = y;
}

// Get the current direction the object is facing
Direction GraphObject::getDirection() const {
    return m_direction;
}

// Set the direction the object is facing
void GraphObject::setDirection(Direction d) {
    m_direction = d;
}
