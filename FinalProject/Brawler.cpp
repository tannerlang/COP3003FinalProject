#include "Brawler.h"


void Brawler::initTexture()
{
	if (!this->brawlerTexture.loadFromFile("Brawler_SouthFace_Default_64x64.png"))
	{
		std::cout << "Texture Load Failure";
	}
}

void Brawler::initSprite()
{
	//set texture to sprite
	this->brawlerSprite.setTexture(this->brawlerTexture);

	//resize sprite

}

