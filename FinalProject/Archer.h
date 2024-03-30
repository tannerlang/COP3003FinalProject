#pragma once
#include "Playable_Character.h"
class Archer : public Playable_Character
{
private:
	sf::Texture archerTexture;
	sf::Sprite archerSprite;

public:

	void initTexture();
	void initSprite();

};

