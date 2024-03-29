#include "Brawler.h"

Brawler::Brawler()
{
	this->initTexture();
	this->initSprite();
};

void Brawler::initTexture()
{
	if (!this->texture.loadFromFile("Brawler_SouthFace_Default_64x64.png"))
	{
		std::cout << "Texture Load Failure";
	}
}

void Brawler::initSprite()
{
	//set texture to sprite
	this->sprite.setTexture(this->texture);

	//resize sprite

}

