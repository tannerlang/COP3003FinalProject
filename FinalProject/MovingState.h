#pragma once
#include "PlayerState.h"
class MovingState :public PlayerState
{
private:

public:
	MovingState()
	{

	}
	virtual void handleInput(Playable_Character& user)				//how to get this user and the one in game.cpp to be the same?
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			//this->user->moveCharacter(-1.f, 0.f);

			if (sf::Event::KeyReleased)
				{
					//change to standing state
					//change sprite image to static default in whatever direction theyre standing
				}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			//this->user->moveCharacter(1.f, 0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			//this->user->moveCharacter(0.f, -1.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			//this->user->moveCharacter(0.f, 1.f);
		}

	}
	virtual void update(Playable_Character& user)
	{

	}

};



