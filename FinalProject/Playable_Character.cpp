#include "Playable_Character.h"
#include<SFML/Graphics.hpp>

Playable_Character::Playable_Character()
{
    this->set_Movement_Speed(10.0);                       //in constructor setting movement speed of the character.
}


void Playable_Character::moveCharacter(const int dirX,const int dirY)
{
	

    this->sprite.move(this->get_Movement_Speed() * dirX, this->get_Movement_Speed() * dirY);                   //need to figure out how to do this with the sprite created in a child class.
                                                                                                             //for now leave it to make sure it works
}