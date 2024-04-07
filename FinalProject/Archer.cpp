#include "Archer.h"

Archer::Archer()
{
	this->initTexture();	//Calls on the pointers 
	this->initSprite();
	this->createHitbox(this->sprite, 1.f, 1.f, 64.f, 64.f);
	this->set_Movement_Speed(5.f);
};

void Archer::initTexture()	//Inputting information into pointers
{
	if (!this->texture.loadFromFile("North_Face.png")) //Displays PNG for archer sprite													 
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

void Archer::handleInput(Playable_Character* user)
{
	switch (state_)
	{
	case Character::STATE_STANDING:


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (!this->texture.loadFromFile("Archer_WestFace_Default_64x64.png"))	//Displays PNG for Brawler
			{
				std::cout << "Texture Load Failure";	//Displays error in case some sort of failure
			}
			user->moveCharacter(-1.f, 0.f);
			//moving left animation
			state_ = STATE_MOVING;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (!this->texture.loadFromFile("Archer_EastFace_Default_64x64.png"))	//Displays PNG for Brawler
			{
				std::cout << "Texture Load Failure";	//Displays error in case some sort of failure
			}
			user->moveCharacter(1.f, 0.f);
			//moving right animation
			state_ = STATE_MOVING;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (!this->texture.loadFromFile("North_Face.png"))	//Displays PNG for Brawler
			{
				std::cout << "Texture Load Failure";	//Displays error in case some sort of failure
			}
			user->moveCharacter(0.f, -1.f);
			//moving up/forward animation
			state_ = STATE_MOVING;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (!this->texture.loadFromFile("South_Face_Static.png"))	//Displays PNG for Brawler
			{
				std::cout << "Texture Load Failure";	//Displays error in case some sort of failure
			}
			user->moveCharacter(0.f, 1.f);
			//moving south animation
			state_ = STATE_MOVING;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			state_ = STATE_ATTACKING;
			//user->attack();
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
	}												//SIMPLE STATE MACHINE. More advanced ones can be made with state objects and pointers. Not yet for me.
}

