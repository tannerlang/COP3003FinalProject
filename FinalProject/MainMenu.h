#pragma once
#include<memory>
#include<SFML/Graphics.hpp>
class MainMenu 
{
private:
	float MMwindowWidth = 500;
	float MMwindowHeight = 500;
	sf::RenderWindow* MMwindow;
	void MMinitWindow();
	sf::Texture BrawlerButton;
	sf::Sprite BrawlerButtonSprite;
	sf::Texture ArcherButton;
	sf::Sprite ArcherButtonSprite;
	
public:
	
	int PlayerClassID;

	sf::RectangleShape rectangle;		

	sf::Text ChooseCharacter;
	sf::Font arial;
	sf::Vector2i mousPos;
	sf::Vector2f BrawlerButtonPos;
	sf::Vector2f BrawlerButtonSize;
	MainMenu();
	virtual ~MainMenu();
	void MMrun();
	void MMupdate();
	void MMrender();
	bool boolOpen();
	void loadText()
	{
		arial.loadFromFile("arial.ttf");
		ChooseCharacter.setFont(arial);
		ChooseCharacter.setString("Choose Your Character!");
		ChooseCharacter.setPosition(100, 50);
	}

	void rect()
	{
		//Square
		sf::RectangleShape rectangle(sf::Vector2f(64, 64));			//Idea is to potentially make a rectangle act as the button, this way you can see the full available selection space
		rectangle.setPosition(100, 50);								//Cannot get rectangle to appear on main menu screen. 
																	//TODO: Get rectangle on screen and attach functions which would be similar to Brawler/Archer
	}

	void loadButton()
	{
		
		//Brawler Button
		if (BrawlerButton.loadFromFile("Brawler_SouthFace_Default_64x64.png"))	//Displays PNG for Brawler
		{
			BrawlerButtonSprite.setTexture(BrawlerButton);
			BrawlerButtonSprite.setPosition(125, 100);
		}
		//Archer Button
		/*if ()
		{
			ArcherButtonSprite.setTexture(BrawlerButton);
			ArcherButtonSprite.setPosition(375, 100);
			
		}*/

	}
	int returnData();
};

