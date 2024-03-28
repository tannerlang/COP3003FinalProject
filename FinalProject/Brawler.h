#pragma once
#include "Playable_Character.h"
class Brawler : public Playable_Character
{
private:
    sf::Texture brawlerTexture;
    sf::Sprite brawlerSprite;
    float movementSpeed;

public:
    
    void initTexture();
    void initSprite();

};

