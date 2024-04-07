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
	delete this->entity;
}

//functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
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
			this->encounter(this->user, this->entity, gameWorld1);
			this->render(); 
			this->entity->skeleton_Movement();
			this->entity->update(this->spawnTimer, this->spawnTimerMax);
			//MOVE Player
			this->user->handleInput(user);				//handles user input, also a simple state machine for player state
			this->user->update();
			
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
		this->user->render(this->window);

		//Draw Enemy		
		this->entity->render(this->window);
		
		//Draw map
		this->window->display();
	}
	
}

void Game::initPlayer(int select)					//using the same select variable that we get from main menu when selecting the object
{	
	
	switch (select)
	{
	case 0:
		
		this->user = &brawler;					//sets the user equal to brawler class.
		break;
	case 1:
		this->user = &archer;					//sets user equal to archer class.
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

void Game::encounter(Playable_Character* user, Skeleton* entity, gameWorld gameWorld1)
{
	if (user->getState() == 2)
	{
		sf::Vector2f userPos = user->sprite.getPosition();
		sf::Vector2f enemyPos = entity->sprite.getPosition();
		//OBJECTIVE: we can call this function when encountering we use the attack function and there is an enemy in range (HAVE TO FIGURE OUT ALL THAT LOGIC)

		int dmg;
		while (this->user->isAlive()) //TODO: need to give functionality for dying for both playable and enemy characters
		{
			//TODO: maybe figure out how to make the user->sprite have a larger global bounds that is invisible to act as a boundary range.
			if (this->user->hitbox->hitbox.getGlobalBounds().contains(enemyPos))//create range boundry for user
			{
				dmg = user->getAttackDamage();
				entity->takeDamage(dmg);
				if (entity->isAlive())
				{
					int entityDmg = entity->getAttackDamage();
					user->takeDamage(entityDmg);
					encounter(user, entity, gameWorld1);		//recursive to keep calling until entity iead.
				}
				if (!user->isAlive())
				{
					delete user;
					break;
				}
				else
				{
					delete entity;
					break;
				}
			}//break if out of range
		}
	}
	
}