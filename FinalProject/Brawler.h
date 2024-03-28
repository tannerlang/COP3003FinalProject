#pragma once
#include "Playable_Character.h"
class Brawler : public Playable_Character
{
private:
    sf::Texture brawlerTexture;
    sf::Sprite brawlerSprite;
public:
    
    void initTexture();
    void initSprite();

};

