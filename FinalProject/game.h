#pragma once
#include "gameWorld.h"
#include "gameTile.h"
#include "CurrentPlayer.h"
#include "buildClass.h"
#include "MainMenu.h"
#include "NPC_Enemy.h"
#include <iostream>
#include <vector>
#include <ctime>


class Game
{

private: 
	bool CharacterSelected = false;  
	float windowWidth = 1920;
	float windowHeight = 1080;
	sf::RenderWindow* window;
	gameWorld gameWorld1 = gameWorld();	

	//Private Functions
	void initPlayer(int select);
	void initEnemy();
	void initWindow();

	//Game logic
	

	
	//Main Menu
	MainMenu menu;

	//Player
	Playable_Character* user;

	//Enemy
	float spawnTimer;
	float spawnTimerMax;
	std::vector<NPC_Enemy*> enemies;
	//NPC_Enemy* enemy;

public:
	//Functions
	

	Game();
	virtual ~Game();
	void run();
	
	void update();
	void updateEnemies();
	void render();
	void selectCharacter(int select);
	void selectCharacterWidget();

};

