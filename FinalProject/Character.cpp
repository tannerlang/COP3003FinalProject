#include "Character.h"
Character::Character()
{
	set_Health(100);

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
