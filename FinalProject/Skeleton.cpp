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
	{													//Placing enemies in a random location
		spawnTimer = 0.f;										//Resets timer every loop
	}
	this->hitbox->update();
}

void Skeleton::moveSkeleton(const int dirX, const int dirY)
{
	this->sprite.move(this->get_Movement_Speed() * dirX, this->get_Movement_Speed() * dirY);                  //moves character                                                                                                         //for now leave it to make sure it works
}

void Skeleton::skeleton_Movement()
{
	
	int Random = rand() % 4;
	while (isAlive()) {
		switch (Random)
		{
		case (0):
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

void Skeleton::aggression(Playable_Character* user, Skeleton* entity, gameWorld gameWorld1)
{
	sf::Vector2f userPos = user->sprite.getPosition();
	sf::Vector2f enemyPos = entity->sprite.getPosition();

	if (userPos.x > enemyPos.x) 
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
