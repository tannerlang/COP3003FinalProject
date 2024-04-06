#pragma once
#include "Character.h"
class Playable_Character : public Character
{
private:

public:
	sf::Text CharacterName;
	sf::Font arial;
	Playable_Character();
	
	void moveCharacter(const int dirX,const int dirY);
	enum PlayerClassID { Brawl, Arch };
	
	virtual void handleInput(Playable_Character* user);
	virtual void attack();
};

