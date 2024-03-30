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
	}
	void loadButton()
	{
		//Brawler Button
		if (!BrawlerButton.loadFromFile("Brawler_SouthFace_Default_64x64.png"))	//Displays PNG for Brawler
		{
			//
		}
		BrawlerButtonSprite.setTexture(BrawlerButton);

		//Archer Button
	}
	int returnData();
};

