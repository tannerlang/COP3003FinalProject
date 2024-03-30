#include "Archer.h"

Archer::Archer()
{
	this->initTexture();	//Calls on the pointers 
	this->initSprite();
};

void Archer::initTexture()	//Inputting information into pointers
{
	if (!this->archerTexture.loadFromFile("Archer.png")) //Displays PNG for archer sprite													 
	{
		std::cout << "Texture Load Failure"; //Displays error in case there is some issue
	}
}

void Archer::initSprite()
{
	this->archerSprite.setTexture(this->archerTexture);	//set texture to sprite
}