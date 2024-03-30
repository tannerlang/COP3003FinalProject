#pragma once

//This class is used with the current player class to create the factory that returns a desired player object
#include"CurrentPlayer.h"
class buildClass :public Brawler,public Archer
{
private:
	Playable_Character* pCharacter;										//initializes variable that points to the address of Playable_Character

public:
	buildClass() 
	{
		pCharacter = nullptr;											//sets pCharacter to null pointer on construction
	}

	void playableCharacterObjectBuilder(PlayerClassID id)				//Function Objective: Use a currentplayer object to build a archer/brawler object using factory function in CurrentPlayer
	{
		CurrentPlayer* cp = new CurrentPlayer();						//creates pointer object to Currentplayer called cp	//keep in mind pointer type when troubleshooting main problem
		pCharacter = cp->factory(id);									//pCharacter now points to object that the factory builds
		delete cp;														//deletes current to CurrentPlayer
	}

	~buildClass()
	{
		if (pCharacter)													//on deconstruction, it deletes pcharacter pointer and sets it to null
		{
			delete pCharacter;
			pCharacter = NULL;
		}
	}

	Playable_Character* getPlayable_Character()
	{
		return pCharacter;												//returns pCharacter... do we use this to set what this object points to a pointer in main called user?
	}
};

