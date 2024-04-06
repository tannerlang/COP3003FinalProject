#include "Playable_Character.h"
#include<SFML/Graphics.hpp>

Playable_Character::Playable_Character()
{
    this->set_Movement_Speed(3.f);                       //in constructor setting movement speed of the character.
}


void Playable_Character::moveCharacter(const int dirX,const int dirY)
{
	

    this->sprite.move(this->get_Movement_Speed() * dirX, this->get_Movement_Speed() * dirY);                   //need to figure out how to do this with the sprite created in a child class.
                                                                                                             //for now leave it to make sure it works
}

void Playable_Character::handleInput(Playable_Character* user)
{
	switch (state_)
	{
	case Character::STATE_STANDING:


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			user->moveCharacter(-1.f, 0.f);
			//moving left animation
			state_ = STATE_MOVING;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			user->moveCharacter(1.f, 0.f);
			//moving right animation
			state_ = STATE_MOVING;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			user->moveCharacter(0.f, -1.f);
			//moving up/forward animation
			state_ = STATE_MOVING;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			user->moveCharacter(0.f, 1.f);
			//moving south animation
			state_ = STATE_MOVING;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			state_ = STATE_ATTACKING;
			user->attack();
		}
		break;

	case Character::STATE_MOVING:
		if (sf::Event::KeyReleased)
		{
			state_ = STATE_STANDING;
			//static animation in the direction left off.
		}
		break;

	case Character::STATE_ATTACKING:
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			state_ = STATE_STANDING;

		}
		break;
	default:
		break;
	}													//SIMPLE STATE MACHINE. More advanced ones can be made with state objects and pointers. Not yet for me.
}

void Playable_Character::attack()
{

}


