#pragma once
#include "gameWorld.h"
#include "gameTile.h"
#include "Brawler.h"
#include "Archer.h"
#include "NPC_Enemy.h"


class Game
{

private: 

	float windowWidth = 1920;
	float windowHeight = 1080;
	sf::RenderWindow* window;
	gameWorld gameWorld1 = gameWorld();	

	//Private Functions
	void initPlayer();
	void initWindow();

	//Player
	Brawler* brawler;

	//Archer* archer;

	//Enemy
	//NPC_Enemy* enemy;

public:
	
	Game();
	virtual ~Game();
	void run();
	void update();
	void render();

};

