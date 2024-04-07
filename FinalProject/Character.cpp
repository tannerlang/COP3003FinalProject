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

	this->createHitbox(this->sprite, 1.f, 1.f, 64.f, 64.f);
}

Character::~Character()
{
	delete this->hitbox;								//deletes hitbox on death for cleanup.
}

//Functions
void Character::update()
{
	this->hitbox->update();
}

void Character::render(sf::RenderTarget* target)
{
	target->draw(this->hitbox->sprite);	
	if (this->hitbox)
	{
		this->hitbox->render(*target);
	}
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

bool Character::isAlive()
{
	return get_Health() > 0;
}

int Character::getAttackDamage()
{
	return damage;
}

void Character::takeDamage(int damage)
{
	set_Health(health - damage);
}

void Character::createHitbox(sf::Sprite& sprite, const float offset_x, const float offset_y, float width, float height)
{
	this->hitbox = new Hitbox(sprite, offset_x, offset_y, width, height);
}

