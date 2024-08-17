#include "GameWorld.h"
#include "GameConstants.h"  // Include this if you have specific game constants or need access to sound IDs
#include <iostream>

GameWorld::GameWorld(std::string assetDir)
    : m_assetDir(std::move(assetDir)), m_lives(3), m_score(0), m_level(1), m_gameStatText("") {}

GameWorld::~GameWorld() {}

void GameWorld::increaseScore(unsigned int howMuch) {
    m_score += howMuch;
}

void GameWorld::setGameStatText(const std::string& text) {
    m_gameStatText = text;
    std::cout << "Game Status: " << m_gameStatText << std::endl;
}

void GameWorld::playSound(int soundID) {

    std::cout << "Playing sound ID: " << soundID << std::endl;

}

bool GameWorld::getKey(int& value) {
    char key;
    std::cin >> key;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        return false;
    }
    value = key;
    return true;
}

