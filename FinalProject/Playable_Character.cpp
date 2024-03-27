#include "Playable_Character.h"
#include<SFML/Graphics.hpp>

void Playable_Character::moveCharacter(int x,int y)
{
	int changeX, changeY;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        // move left...
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        // move right...
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //move up
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        //move down
    }

    //add controller support
}