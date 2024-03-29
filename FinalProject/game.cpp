#include "game.h"


//private function
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Final Project");
}


Game::Game()
{
	this->initWindow();
	gameWorld gameWorld1 = gameWorld();

}

Game::~Game()
{

}

void Game::run()
{

}