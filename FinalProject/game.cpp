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

	if (this->user->isAlive())
	{
		
		delete this->user;
		this->user = nullptr;
	}

	if (this->entity != nullptr)
	{
		
		delete this->entity;
		this->entity = nullptr;
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
			this->debugEvents();

			//calls encounter function (handles combat)
			if (this->entity != nullptr && this->user != nullptr)
			{
				encounter();
			}

			if (this->entity != nullptr)
			{ 
			this->entity->skeleton_Movement();
			this->entity->aggression(this->user,this->entity,this->gameWorld1);
			this->entity->update(this->spawnTimer, this->spawnTimerMax);
			}

			//MOVE Player
			if (this->user != nullptr)
			{
				this->user->handleInput(user);				//handles user input, also a simple state machine for player state
				this->user->update();
			}
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
		if (this->user != nullptr)
		{
			this->user->render(this->window);
		}

		if (this->entity != nullptr)
		{
			//Draw Enemy		
			this->entity->render(this->window);
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


void Game::encounter()
{
		//OBJECTIVE: we can call this function when encountering we use the attack function and there is an enemy in range (HAVE TO FIGURE OUT ALL THAT LOGIC)
		int dmg;
		while (this->user->getState() == 2 && this->entity != nullptr && this->user != nullptr)
		{
			//TODO: maybe figure out how to make the user->sprite have a larger global bounds that is invisible to act as a boundary range.
			if (this->user->hitbox->sprite.getGlobalBounds().contains(this->entity->hitbox->sprite.getPosition().x, this->entity->hitbox->sprite.getPosition().y)) //create range boundry for user
			{
				dmg = this->user->getAttackDamage();

				this->entity->takeDamage(dmg);

				if (this->entity->isAlive())
				{
					int entityDmg = this->entity->getAttackDamage();
					this->user->takeDamage(entityDmg);
					encounter();		//recursive to keep calling until entity dead.
				}
				else if (!this->user->isAlive())
				{
					delete this->user;
					this->user = nullptr;
				}
				else if (!this->entity->isAlive())
				{
					delete this->entity;
					this->entity = nullptr;
				}
			}//break if out of range
		}
}

void Game::destroy(Character* obj)
{
	obj = nullptr;
	delete obj;
}

void Game::debugEvents()
{
	//-----------------------SKELETON DEBUGGING-------------
			//TESTING USER DELETION
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		delete this->entity;
		this->entity = nullptr;
	}
	//-------------------------------------------------------

	//---------------------USER DEBUGGING-----------------
		//
	//-------------------------------------------------------

}
