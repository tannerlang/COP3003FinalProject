#pragma once
#include "gameWorld.h"
#include "gameTile.h"
#include "CurrentPlayer.h"
#include "buildClass.h"
#include "MainMenu.h"
#include "Skeleton.h"
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
	Skeleton* entity = new Skeleton();
	Brawler  brawler;
	Archer archer;
	
	//Enemy
	float spawnTimer;
	float spawnTimerMax;
	

public:
	//Functions
	

	Game();
	virtual ~Game();
	void run();
	
	void update();
	void render();
	void selectCharacter(int select);
	void selectCharacterWidget();
	int* selectPtr;

	//OBJECTIVE: we can call this function when encountering we use the attack function and there is an enemy in range

	void encounter(Playable_Character* user, Skeleton* entity, gameWorld gameWorld1);

	void encounter(Playable_Character* user, Skeleton* entity, gameWorld* gameWorld1);
	

};