#include<SFML/Graphics.hpp>
#include "gameWorld.h"
#include "gameTile.h"

int main()
{
	/*Creating Window*/

	float windowWidth = 1920;
	float windowHeight = 1080;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Final Project");

	gameWorld gameWorld1 = gameWorld();


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
	//Committing to the test
//pull test
}
