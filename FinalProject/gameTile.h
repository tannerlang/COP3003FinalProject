#pragma once
#include <SFML/Graphics.hpp>
#ifndef GAMETILE_H
#define GAMETILE_H

class gameTile
{

public:

	bool isPassable;
	bool isExit;

	sf::Vector2f pos;						//2d vector pos initialized
	sf::Texture texture;					//texture initialized
	sf::Sprite sprite;						//sprite initialized

	gameTile(std::string, float, float, bool, bool);
	bool setUpSprite(std::string);

};


#endif
