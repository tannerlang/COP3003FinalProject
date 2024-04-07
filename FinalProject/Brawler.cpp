#include "Brawler.h"

Brawler::Brawler()
{
	this->initTexture();	//Calls on the pointers which will be holding the PNG
	this->initSprite();
	this->initText();		//text for debugging
};

void Brawler::initTexture()	//Inputting information to pointer
{
	if (!this->texture.loadFromFile("Brawler_SouthFace_Default_64x64.png"))	//Displays PNG for Brawler
	{
		std::cout << "Texture Load Failure";	//Displays error in case some sort of failure
	}
}

void Brawler::initSprite()	
{
	this->sprite.setTexture(this->texture);	//set texture to sprite
}

void Brawler::initText()
{
	arial.loadFromFile("arial.ttf");
	CharacterName.setFont(arial);
	CharacterName.setString("Brawler");
	CharacterName.setPosition(0, 0);
}

void Brawler::handleInput(Playable_Character* user)				//overriding handleinput function.
{
	switch (state_)
	{
	case Character::STATE_STANDING:

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			
			if (!this->texture.loadFromFile("Brawler_WestFace_Default_64x64.png"))	//Displays PNG for Brawler
			{
				std::cout << "Texture Load Failure";	//Displays error in case some sort of failure
			}
			user->moveCharacter(-1.f, 0.f);
			
			state_ = STATE_MOVING;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			user->moveCharacter(1.f, 0.f);

			if (!this->texture.loadFromFile("Brawler_EastFace_Default_64x64.png"))	//Displays PNG for Brawler
			{
				std::cout << "Texture Load Failure";	//Displays error in case some sort of failure
			}
			state_ = STATE_MOVING;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			user->moveCharacter(0.f, -1.f);

			if (!this->texture.loadFromFile("Brawler_NorthFace_Default_64x64.png"))	//Displays PNG for Brawler
			{
				std::cout << "Texture Load Failure";	//Displays error in case some sort of failure
			}
			state_ = STATE_MOVING;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			user->moveCharacter(0.f, 1.f);

			if (!this->texture.loadFromFile("Brawler_SouthFace_Default_64x64.png"))	//Displays PNG for Brawler
			{
				std::cout << "Texture Load Failure";	//Displays error in case some sort of failure
			}
			state_ = STATE_MOVING;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			state_ = STATE_ATTACKING;
			if (!this->texture.loadFromFile("Brawler_SouthFace_Attack1_64x64.png.png"))	//Displays PNG for Brawler
			{
				std::cout << "Texture Load Failure";	//Displays error in case some sort of failure
			}
			user->attack();
		}

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
		}																	//SIMPLE STATE MACHINE. More advanced ones can be made with state objects and pointers. Not yet for me.
}

void Brawler::attack()
{
	while (isAlive())
	{
		/*if (in range of an enemy entity on the map)
		{
			
		}*/
	}
}

	
