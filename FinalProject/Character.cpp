#include "Character.h"
Character::Character()
{
	set_Health(100);

	//init core stats
	max_health = 100;
	max_stamina = 100;
	stamina = 50;
	damage = 50;
	dodge;
	speed = 50;
	attack_speed = 50;
	crit_chance = 0.1;
	level = 1;
	exp = 0;

	//init base attributes
	vitality = 20;	
	strength = 20;	
	agility = 20;	
	dexterity = 20;

}

Character::~Character()
{

}

void update()
{

}

void render()
{

}

int Character::get_Health()
{
	return health;
}

void Character::set_Health(int h)
{
	h = health;
}

void Character::set_Movement_Speed(float x)
{
	movementSpeed = x;
}

float Character::get_Movement_Speed()
{
	return movementSpeed;
}