#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class gameWorld {


	sf::Vector2i exitPos;
	sf::Vector2i playerPos;
	std::vector<sf::Vector2i> enemyPositions;
	void setUpInitialState();
	void setUpEnemyPositions();
	void setUpTiles();

public:

	std::vector< std::vector<gameTile*> > tiles;
	int gridLength;
	gameWorld();
};

#endif