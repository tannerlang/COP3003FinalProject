#pragma once
#include "gameWorld.h"
#include "gameTile.h"
#include "CurrentPlayer.h"
#include "buildClass.h"
#include "MainMenu.h"
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
	void initVariables();
	void initEnemy();
	void initWindow();

	//Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	
	//Main Menu
	MainMenu menu;

	//Player
	Playable_Character* user;

	//Enemy
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;
	//NPC_Enemy* enemy;

public:
	//Functions
	void spawnEnemy();

	Game();
	virtual ~Game();
	void run();
	void updateEnemies();
	void update();
	void renderEnemies();
	void render();
	void selectCharacter(int select);
	void selectCharacterWidget();

};

