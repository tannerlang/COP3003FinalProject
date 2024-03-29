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
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->brawler;
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
			this->brawler->moveCharacter(-1.f, 0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->brawler->moveCharacter(1.f, 0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->brawler->moveCharacter(0.f, -1.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->brawler->moveCharacter(0.f, 1.f);
		}
		//TODO: add controller support
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

	//Draw player
	this->brawler->render(*this->window);										//drawing brawler to screen

	this->window->display();
}

void Game::initPlayer()
{	//if character is brawler
	this->brawler = new Brawler();


	//if character is archer
}