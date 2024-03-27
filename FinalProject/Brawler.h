#pragma once
#include "Playable_Character.h"
class Brawler : public Playable_Character
{
public:
    sf::Texture brawlerTexture;
    sf::Sprite brawlerSprite;
    void initTexture();
    void initSprite();

};

