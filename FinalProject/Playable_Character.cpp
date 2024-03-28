#include "Playable_Character.h"
#include<SFML/Graphics.hpp>

Playable_Character::Playable_Character()
{
    this->set_Movement_Speed(10.0);                       //in constructor setting movement speed of the character.
}


void Playable_Character::moveCharacter(const int x,const int y)
{
	int changeX, changeY;

    this->brawlerSprite.move(this->get_Movement_Speed() * x, this->get_Movement_Speed() * y);
}