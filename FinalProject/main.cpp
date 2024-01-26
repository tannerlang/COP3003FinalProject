#include<SFML/Graphics.hpp>


int main()
{
	/*Creating Window*/

	float windowWidth = 1920;
	float windowHeight = 1080;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Final Project");

	sf::Texture texture;
	(texture.loadFromFile("map.png"));
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
		window.draw(sprite);
		window.display();

	}
	//Committing to the test
//pull test
}
