#include "Archer.h"

Archer::Archer()
{
	this->initTexture();	//Calls on the pointers 
	this->initSprite();
};

void Archer::initTexture()	//Inputting information into pointers
{
	if (!this->texture.loadFromFile("Archer.png")) //Displays PNG for archer sprite													 
	{
		std::cout << "Texture Load Failure"; //Displays error in case there is some issue
	}
}

void Archer::initSprite()
{
	this->sprite.setTexture(this->texture);	//set texture to sprite
}