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
		
		for (int i = 0; i < gameWorld1.gridLength; i++) {
			for (int j = 0; j < gameWorld1.gridLength; j++) {
				window.draw(gameWorld1.tiles[i][j]->sprite);
			}
		}



		window.display();

	}
	//Committing to the test
//pull test
}
