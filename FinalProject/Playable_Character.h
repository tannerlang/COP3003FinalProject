#pragma once
#include "Character.h"
class Playable_Character : public Character
{
private:
	sf::Texture brawlerTexture;
	sf::Sprite brawlerSprite;										//need to figure out how to use th
public:
	Playable_Character();
	
	void moveCharacter(const int x,const int y);

};

