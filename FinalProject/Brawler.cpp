#include "Brawler.h"

Brawler::Brawler()
{
	this->initTexture();	//Calls on the pointers which will be holding the PNG
	this->initSprite();
};

void Brawler::initTexture()	//Inputting information to pointer
{
	if (!this->texture.loadFromFile("Brawler.png"))	//Displays PNG for Brawler
	{
		std::cout << "Texture Load Failure";	//Displays error in case some sort of failure
	}
}

void Brawler::initSprite()	
{
	this->sprite.setTexture(this->texture);	//set texture to sprite
}

