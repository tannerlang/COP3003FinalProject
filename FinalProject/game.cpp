#include "game.h"


//private functions
void Game::initVariables()
{
	this->window = nullptr;


	//Game logic
	this->points = 0;
	this->enemySpawnTimer = 0.f;
	this->enemySpawnTimerMax = this->enemySpawnTimer;
	this->maxEnemies = 5;


}
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
	//delete this->enemy;
}

//functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();									
	}
}

//function to handle enemy updates each frame
void Game::updateEnemies()
{
	/*
		Updates the enemy spawn timer and spawns enemies
		when the total amount of enemies is smaller than the max
		Moves the enemies downwards.
		Removes the enemies at the edge of the screen. //TODO
	*/

	//Updating timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies)
	{
		//this->spawnTimer += 0.5f;
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//this->enemy.push_back(new Enemy(rand() % 200, rand() % 200));
			//Spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
		{
			this->enemySpawnTimer += 1.f;
		}
	}

	//Move the enemies
	for (auto &e : this ->enemies)
	{
		e.move(0.f, 5.f);
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
			//Move player
			//STATE MACHINE: IN PROGRESS
	
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				this->user->moveCharacter(-1.f, 0.f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				this->user->moveCharacter(1.f, 0.f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				this->user->moveCharacter(0.f, -1.f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				this->user->moveCharacter(0.f, 1.f);
			}
			//TODO: add controller support
		}
	}
}

void Game::renderEnemies()
{

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

		//Drawing game object
		this->renderEnemies();

		//Draw map
		this->window->display();
	}
	
}

void Game::initPlayer(int select)					//using the same select variable that we get from main menu when selecting the object
{	
	
	switch (select)
	{
	case 0:
		this->user = new Brawler();
		break;
	case 1:
		this->user = new Archer();
	default:
		break;
	}
}

//Function to initialize enemy
void Game::initEnemy()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);


}

void Game::spawnEnemy()
{
	/*
		Spawns enemies and sets their color and positions.
		-Sets a random position.
		-Sets a random color.
		-Adds enemy to the vector.
	*/

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
	);
	
	this->enemy.setFillColor(sf::Color::Green);

	//Spawn the enemy
	this->enemies.push_back(this->enemy);
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
	selectCharacter(select);
}

