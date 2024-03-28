#include<SFML/Graphics.hpp>
#include "gameWorld.h"
#include "gameTile.h"
#include"Brawler.h"
#include"game.h"
int main()
{
	//------------------------------NOTE TO SELF, DIVIDE THESE UP INTO FUNCTIONS-------------------------------------
	/*Creating Window*/

	float windowWidth = 1920;
	float windowHeight = 1080;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Final Project");

	gameWorld gameWorld1 = gameWorld();

	//------------------------------UPDATE FUNCTION--------------------------------------------------------------------
	/*Gameloop*/
	while (window.isOpen())
	{
		/*Event*/
		sf::Event event;
		while (window.pollEvent(event))
		{
			/*Exit*/
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		//TODO: create function to pick a class which would create the respective character object, brawler or archer
		Brawler* player;
		//may have to have the gameloop be an object and etc.. youtube video 5:42
		//moving player
		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			// move left...
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			// move right...
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			//move up
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			//move down
		}
		*/
		//add controller support

//------------------------------RENDER FUNCTION-----------------------------------------------------------------------
		window.clear();

		for (int row = 0; row < gameWorld1.tiles.size(); row++) 
		{
			for (int col = 0; col < gameWorld1.tiles[row].size(); col++) 
			{
				window.draw(gameWorld1.tiles[row][col]->sprite);
			}
		}

		window.display();
	}
}
