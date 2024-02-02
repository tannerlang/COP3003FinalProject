#include<SFML/Graphics.hpp>
#include "gameWorld.cpp"
#include "gameTile.cpp"

int main()
{
	/*Creating Window*/

	float windowWidth = 1920;
	float windowHeight = 1080;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Final Project");

	gameWorld gameWorld = gameWorld();


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
		
		for (int i = 0; i < gameWorld.gridLength; i++) {
			for (int j = 0; j < gameWorld.gridLength; j++) {
				window.draw(gameWorld.tiles[i][j]->sprite);
			}
		}



		window.display();

	}
	//Committing to the test
//pull test
}
