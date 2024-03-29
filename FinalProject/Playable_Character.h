#pragma once
#include "Character.h"
class Playable_Character : public Character
{
private:

public:
	Playable_Character();
	
	void moveCharacter(const int x,const int y);

};

