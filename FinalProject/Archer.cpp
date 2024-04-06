#include "Archer.h"

Archer::Archer()
{
	this->initTexture();	//Calls on the pointers 
	this->initSprite();
};

void Archer::initTexture()	//Inputting information into pointers
{
	if (!this->texture.loadFromFile("Archer.png")) //Displays PNG for archer sprite													 
	{
		std::cout << "Texture Load Failure"; //Displays error in case there is some issue
	}
}

void Archer::initSprite()
{
	this->sprite.setTexture(this->texture);	//set texture to sprite
}

void Archer::initText()
{
	arial.loadFromFile("arial.ttf");
	CharacterName.setFont(arial);
	CharacterName.setString("Archer");
	CharacterName.setPosition(0, 0);
}

void Archer::handleInput(Archer* user)
{
	switch (state_)
	{
	case Character::STATE_STANDING:

		state_ = STATE_MOVING;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			user->moveCharacter(-1.f, 0.f);
			//moving left animation
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			user->moveCharacter(1.f, 0.f);
			//moving right animation
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			user->moveCharacter(0.f, -1.f);
			//moving up/forward animation
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			user->moveCharacter(0.f, 1.f);
			//moving south animation
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
		//not yet functional.
		break;
	default:
		break;
	}																	//SIMPLE STATE MACHINE. More advanced ones can be made with state objects and pointers. Not yet for me.
}