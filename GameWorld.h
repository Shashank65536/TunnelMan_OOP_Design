// This is the sample gameworld.h file and based on this file the classes are designed according to the pdf.
#ifndef GAMEWORLD_H  // If GAMEWORLD_H is not defined

#define GAMEWORLD_H

#include <string>

class GameWorld
{
public:
    
    explicit GameWorld(std::string assetDir) : m_assetDir(std::move(assetDir)) {}

    
    virtual ~GameWorld() {}

    
    virtual int init() = 0;

    
    virtual int move() = 0;

    
    virtual void cleanUp() = 0;

    unsigned int getLives() const { return m_lives; }
    void incLives() { ++m_lives; }
    void decLives() { if (m_lives > 0) --m_lives; }
    unsigned int getScore() const { return m_score; }
    void increaseScore(unsigned int howMuch) { m_score += howMuch; }
    unsigned int getLevel() const { return m_level; }
    void setGameStatText(const std::string& text) { m_gameStatText = text; }
    bool getKey(int& value);

protected:
    std::string m_assetDir;
    unsigned int m_lives;
    unsigned int m_score;
    unsigned int m_level;
    std::string m_gameStatText;

   
    void playSound(int soundID);
};

#endif // GAMEWORLD_H
