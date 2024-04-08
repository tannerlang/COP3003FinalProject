#include "Skeleton.h"

Skeleton::Skeleton()
{
	this->initTexture();
	this->initSprite();
	this->set_Damage();
	this->set_Movement_Speed(1.f);
	this->createHitbox(this->sprite, 1.f, 1.f, 64.f, 64.f);
}

Skeleton::~Skeleton()
{
	

}
void Skeleton::set_Damage()
{
	damage = 10;
}

//Public functions
void Skeleton::initTexture()
{
	if (!this->texture.loadFromFile("Skeleton.png")) //upload PNG of the enemy
	{
		std::cout << "Texture Load Failure";
	}
}

void Skeleton::initSprite()
{
	//set texture to sprite
	this->sprite.setTexture(this->texture);
}

void Skeleton::update(float spawnTimer, float spawnTimerMax)
{
	//Spawning enemies
	spawnTimer += 0.5f;										//Keeps spawn timer increasing
	if (spawnTimer >= spawnTimerMax)					//Checks if spawn timer is greater than the max
	{	
																//Placing enemies in a random location
		spawnTimer = 0.f;										//Resets timer every loop
	}
	this->hitbox->update();
}

void Skeleton::moveSkeleton(const int dirX, const int dirY)
{
	this->sprite.move(this->get_Movement_Speed() * dirX, this->get_Movement_Speed() * dirY);                  //moves character                                                                                                         //for now leave it to make sure it works
}

void Skeleton::skeleton_Movement()		//this function might be useless. Need to try removing from here and game.cpp
{
	
	int Random = rand() % 4;			//Generates a random int from 0-3
	while (isAlive()) {					//Still working on incorporating isAlive
		switch (Random)
		{
		case (0):						//While number is being generated the skeleton is being moved
			moveSkeleton(1.f, 1.f);
		case (1):
			moveSkeleton(-1.f, 1.f);
		case (2):
			moveSkeleton(1.f, -1.f);
		case (3):
			moveSkeleton(1.f, 1.f);
		}


	}
}

void Skeleton::aggression(Playable_Character* user, Skeleton* entity, gameWorld gameWorld1)			//Aggression is meant to keep skeleton moving towards character
{																									//Need to try to incorporate isAlive also more of a radius rather than constantly moving towards player
	sf::Vector2f userPos = user->sprite.getPosition();												//Getting position of Player & Skeleton
	sf::Vector2f enemyPos = entity->sprite.getPosition();		

	if (distance(userPos.x, userPos.y, enemyPos.x, enemyPos.y) < 100.f) 
	{
		if (userPos.x > enemyPos.x)																		//if ladder to keep Skeleton moving towards player
		{
			moveSkeleton(1.f, 0.f);
		}
		if (userPos.y > enemyPos.y)
		{
			moveSkeleton(0.f, 1.f);
		}
		if (userPos.x < enemyPos.x)
		{
			moveSkeleton(-1.f, 0.f);
		}
		if (userPos.y < enemyPos.y)
		{
			moveSkeleton(0.f, -1.f);
		}
	}

	if (distance(userPos.x, userPos.y, enemyPos.x, enemyPos.y) < 20.f)
	{
		int playerHealth;
		playerHealth = user->get_Health();
		playerHealth = playerHealth - this->getAttackDamage();
		user->set_Health(playerHealth);
	}
	

}

double Skeleton::distance(double x1, double y1, double x2, double y2)
{
	return std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));				//Distance formula to detect player
}

int Skeleton::getAttackDamage()
{
	return damage;
}

void Skeleton::takeDamage(int damage)
{
	int health;
	health = this->get_Health();
	health = health - damage;
	this->set_Health(health);
}
