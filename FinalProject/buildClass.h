#pragma once

//This class is used with the current player class to create the factory that returns a desired player object
#include"CurrentPlayer.h"
class buildClass :public Brawler,public Archer
{
private:
	Playable_Character* pCharacter;

public:
	buildClass() 
	{
		pCharacter = nullptr;
	}

	void playableCharacterObject(PlayerClassID id)
	{
		CurrentPlayer* cp = new CurrentPlayer();
		pCharacter = cp->build(id);
		delete cp;
	}

	~buildClass()
	{
		if (pCharacter)
		{
			delete pCharacter;
			pCharacter = NULL;
		}
	}

	Playable_Character* getPlayable_Character()
	{
		return pCharacter;
	}
};

