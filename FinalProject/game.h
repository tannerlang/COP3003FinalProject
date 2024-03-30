#pragma once
#include "gameWorld.h"
#include "gameTile.h"
#include "Archer.h"
#include "Brawler.h"
#include "CurrentPlayer.h"
#include "buildClass.h"
#include <iostream>


class Game
{

private: 
	bool CharacterSelected = false;
	float windowWidth = 1920;
	float windowHeight = 1080;
	sf::RenderWindow* window;
	gameWorld gameWorld1 = gameWorld();	

	//Private Functions
	void initPlayer();
	void initWindow();

	//Player
	Playable_Character* user;


	//Enemy
	//NPC_Enemy* enemy;

public:
	
	Game();
	virtual ~Game();
	void run();
	void update();
	void render();
	void selectCharacter(int select);
	void selectCharacterWidget();

};

