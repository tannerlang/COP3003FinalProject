#include "game.h"


//private function
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Final Project");
	
}

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();									
		this->render();
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
			if (event.KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
		}
	}
}

//draws at updated position
void Game::render()
{
	this->window->clear();

	//drawing map TODO:!!!(FIGURE OUT WHY MAP ISNT POPULATING ANYMORE)!!!
	for (int row = 0; row < gameWorld1.tiles.size(); row++)
	{
		for (int col = 0; col < gameWorld1.tiles[row].size(); col++)
		{
			this->window->draw(gameWorld1.tiles[row][col]->sprite);
		}
	}

	this->window->display();
}