#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class gameWorld {


	sf::Vector2i exitPos;											//two dimension vector exitPos
	sf::Vector2i playerPos;											//two dimension vector for play position.
	std::vector<sf::Vector2i> enemyPositions;						//two dimension vector for enemy positon.
	void setUpInitialState();
	void setUpEnemyPositions();
	void setUpTiles();

public:

	std::vector< std::vector<gameTile*>> tiles;						//Creating a vector within a vector
	int gridLength,gridHeight;										//Variables to later on determine grid for charactor/enemy movement
	gameWorld();													//Creating constructor
};

#endif