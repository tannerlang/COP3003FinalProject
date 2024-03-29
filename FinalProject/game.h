#pragma once
#include "game.h"
#include "gameWorld.h"
#include "gameTile.h"
#include<SFML/Graphics.hpp>

class Game
{
private: 

	float windowWidth = 1920;
	float windowHeight = 1080;
	sf::RenderWindow* window;
	void initWindow();
	gameWorld gameWorld1 = gameWorld();

public:
	Game();
	virtual ~Game();

	void run();
	void update();
	void render();

};

