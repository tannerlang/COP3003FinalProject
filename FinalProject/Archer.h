#pragma once
#include "Playable_Character.h"
class Archer : public Playable_Character
{
private:
	sf::Texture archerTexture;
	sf::Sprite archerSprite;

public:

	Archer();
	void initTexture();
	void initSprite();

};

