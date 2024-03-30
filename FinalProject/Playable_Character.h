#pragma once
#include "Character.h"
class Playable_Character : public Character
{
private:

public:
	
	Playable_Character();
	
	void moveCharacter(const int dirX,const int dirY);
	enum PlayerClassID { Brawl, Arch };
	
};

