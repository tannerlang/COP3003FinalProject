#include<SFML/Graphics.hpp>


int main()
{
	/*Creating Window*/

	float windowWidth = 1920;
	float windowHeight = 1080;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Final Project");

	sf::Texture texture;
	(texture.loadFromFile("Brawler_SouthFace_Default_64x64.png"));
	sf::Sprite sprite;
	sprite.setTexture(texture);

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
		
		window.display();

	}
	//Committing to the test
//pull test
}
