#pragma once
#include "Playable_Character.h"
class Archer : public virtual Playable_Character
{
private:
	

public:
	Archer();
	void initTexture();
	void initSprite();
	void initText();
	void handleInput(Playable_Character* user);
};

