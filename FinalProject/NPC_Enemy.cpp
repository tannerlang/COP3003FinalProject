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

void NPC_Enemy::update(float spawnTimer, float spawnTimerMax)
{

}

//Public functions
void NPC_Enemy::initTexture()
{
	
}

void NPC_Enemy::initSprite()
{
	
}

void NPC_Enemy::aggression()
{

}



