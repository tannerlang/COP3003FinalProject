#include "Brawler.h"

Brawler::Brawler()
{
	this->initTexture();	//Calls on the pointers which will be holding the PNG
	this->initSprite();
	this->initText();		//text for debugging
};

void Brawler::initTexture()	//Inputting information to pointer
{
	if (!this->texture.loadFromFile("Brawler_SouthFace_Default_64x64.png"))	//Displays PNG for Brawler
	{
		std::cout << "Texture Load Failure";	//Displays error in case some sort of failure
	}
}

void Brawler::initSprite()	
{
	this->sprite.setTexture(this->texture);	//set texture to sprite
}

void Brawler::initText()
{
	arial.loadFromFile("arial.ttf");
	CharacterName.setFont(arial);
	CharacterName.setString("Brawler");
	CharacterName.setPosition(0, 0);
}

//a way to do the alternating sprate pngs for animations: access the moving member function via brawler, make a while loop while walking, and in the while loop create a function
//or algorithm to switches the images and detects direction of last input to display static frames as well.