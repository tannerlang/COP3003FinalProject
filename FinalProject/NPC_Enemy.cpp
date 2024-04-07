#include "NPC_Enemy.h"



NPC_Enemy::NPC_Enemy()
{
	this->initTexture();
	this->initSprite();
	this->set_Damage();
	this->set_Movement_Speed(3.f);
	
}

void NPC_Enemy::set_Damage()
{
	damage = 10;
}

//Public functions
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


