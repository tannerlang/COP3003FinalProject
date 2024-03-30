#include "game.h"


//private function
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Final Project");
	this->window->setFramerateLimit(240);
	this->window->setVerticalSyncEnabled(false);
	
}

Game::Game()
{
	
	user = nullptr;
	this->selectCharacterWidget();
	this->initWindow();
	this->initPlayer();
	
	
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
			//Move player
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

	
	if (CharacterSelected)					//this currently draw screen white (since bool is false) game doesnt crash anymore. Will draw screen when character is selected.
	{
		//Draw Player
		this->user->render(*this->window);

		//Draw map
		this->window->display();
	}
	
}

void Game::initPlayer()			//Should an initEnemy function be made? probably
{	
	//this->user = new class() is set up in select character now.
}


void Game::selectCharacter(int select)											//Function Objective: Call in game() to select character, 
{
	
	//link this 'select' argument with a widget to select character.
	//TODO:Tweak the pointers in this function to fix the crashing. 
	buildClass* pbuildClass = new buildClass();									//creates pointer to buldClass called pbuildClass and initializes it.
	
	if (select == 0)
	{
		pbuildClass->playableCharacterObjectBuilder(Playable_Character::Brawl);	//using pointer, call object builder an pass "code" which tells factory what object to build.			
		user = pbuildClass->getPlayable_Character();							//sets user(pointer to playable character object) equal to the object that the factory built
		CharacterSelected = true;
	}
	if (select == 1)
	{
		pbuildClass->playableCharacterObjectBuilder(Playable_Character::Arch);			
		user = pbuildClass->getPlayable_Character();			
		CharacterSelected = true;
	}
	else
	{
		delete pbuildClass;
	}
	
	
}	//Outcome: sets user object equal to address of new brawler / new archer object made behind the scenes.

void Game::selectCharacterWidget()
{
	this->menu = MainMenu();
	menu.MMrun();





	int select = 0;
	selectCharacter(select);
}

