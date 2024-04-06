#include "game.h"


//private functions

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Final Project");
	this->window->setFramerateLimit(240);
	this->window->setVerticalSyncEnabled(false);
	
}

Game::Game()
{
	this->selectCharacterWidget();
	this->initWindow();
	this->initEnemy();
	
}

Game::~Game()
{
	delete this->window;
	delete this->user;

	//Deleting enemies to conserve memory
	for (auto* i : this->enemies)
	{
		delete i;
	}
}

//functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();

	}
}

void Game::updateEnemies()
{
	//Spawning enemies
	this->spawnTimer += 0.5f;						//Keeps spawn timer increasing
	if (this->spawnTimer >= this->spawnTimerMax)	//Checks if spawn timer is greater than the max
	{
		this->enemies.push_back(new NPC_Enemy(rand() % 200, rand() % 200)); //Placing enemies in a random location
		this->spawnTimer = 0.f;						//Resets timer every loop
	}
	for (auto* enemy : this->enemies)
	{
		enemy->update();
	}
}


//function to handle data updates each frame
void Game::update()
{
	while (!menu.boolOpen())
	{

		while (this->window->isOpen())
		{
			sf::Event event;
			while (this->window->pollEvent(event))
			{

				///Exit
				if (event.type == sf::Event::Closed)
				{
					this->window->close();
				}
			}
			this->render(); 
			this->updateEnemies();
			//MOVE Player
			this->user->handleInput(user);				//handles user input, also a simple state machine for player state
		}
	}
}

//draws at updated position
void Game::render()
{
	this->window->clear();
	
	//drawing map 
	for (int row = 0; row < gameWorld1.tiles.size(); row++)						//gameWorld1.tiles.size() returns num of elements
	{
		for (int col = 0; col < gameWorld1.tiles[row].size(); col++)			//tiles vector's element is a vector, calling that size, which is size of gridLength
		{
			this->window->draw(gameWorld1.tiles[row][col]->sprite);				//drawing the sprite in column vector, which is a vector in the row vector
		}
	}

	
	if (CharacterSelected)					
	{
		//Draw Player
		this->user->render(*this->window);

		for (auto* enemy : this->enemies)
		{
			enemy->render(this->window);
		}
		//Draw map
		this->window->display();
	}
	
}

void Game::initPlayer(int select)					//using the same select variable that we get from main menu when selecting the object
{	
	
	switch (select)
	{
	case 0:
		
		this->user = &brawler;
		break;
	case 1:
		this->user = &archer;
	default:
		break;
	}
}

void Game::initEnemy()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;

	
}


void Game::selectCharacter(int select)											//Function Objective: Call in game() to select character, 
{
	
	buildClass* pbuildClass = new buildClass();									//creates pointer to buildClass called pbuildClass and initializes it.
	switch (select)
	{
	case 0:
		pbuildClass->playableCharacterObjectBuilder(Playable_Character::Brawl);	//using pointer, call object builder an pass "code" which tells factory what object to build.			
		user = pbuildClass->getPlayable_Character();							//sets user(pointer to playable character object) equal to the object that the factory built
		CharacterSelected = true;
		delete pbuildClass;
		break;
	case 1:
		pbuildClass->playableCharacterObjectBuilder(Playable_Character::Arch);
		user = pbuildClass->getPlayable_Character();
		CharacterSelected = true;
		delete pbuildClass;
		break;
	default:
		delete pbuildClass;
		break;
	}
	initPlayer(select);
}	//Outcome: sets user object equal to address of new brawler / new archer object made behind the scenes.

void Game::selectCharacterWidget()
{
	
	menu.MMrun();								//this works. 
	int select = menu.returnData();
	selectPtr = &select;
	selectCharacter(select);
	
}

