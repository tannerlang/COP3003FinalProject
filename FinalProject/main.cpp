#include<SFML/Graphics.hpp>


int main()
{
	/*Creating Window*/
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Final Project");


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
	}
	//Commit test

}