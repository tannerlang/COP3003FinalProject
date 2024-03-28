#pragma once
#include "game.h"
#include "gameWorld.h"
#include "gameTile.h"
#include<SFML/Graphics.hpp>

class Game
{
private: 
	sf::RenderWindow* window;

public:
	Game();
	virtual ~Game();

	void run();

};

