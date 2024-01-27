#include "Character.h"
Character::Character()
{
	set_Health(100);

	//init core stats
	int max_health = 100;
	int max_stamina = 100;
	int stamina = 50;
	int damage = 50;
	bool dodge;
	int speed = 50;
	int attack_speed = 50;
	float crit_chance = 0.1;
	int level = 1;
	int exp = 0;

	//init base attributes
	int vitality = 20;	
	int strength = 20;	
	int agility = 20;	
	int dexterity = 20;

}

Character::~Character()
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
