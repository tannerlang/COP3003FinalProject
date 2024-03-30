#include "NPC_Enemy.h"

NPC_Enemy::NPC_Enemy()
{
	this->initTexture();
	this->initSprite();
};

void NPC_Enemy::initTexture()
{
	if (!this->texture.loadFromFile("NPC_Enemy.png")) //upload PNG of the enemy
	{
		std::cout << "Texture Load Failure";
	}
}

void NPC_Enemy::initSprite()
{
	//set texture to sprite
	this->sprite.setTexture(this->texture);
}
