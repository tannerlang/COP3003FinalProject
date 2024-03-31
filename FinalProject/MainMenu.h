#pragma once
#include<memory>
#include"Playable_Character.h"
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
	sf::RectangleShape brawl_rect;
	sf::RectangleShape arch_rect;
	sf::Text ChooseCharacter;
	sf::Font arial;
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
		//Brawler background
		sf::RectangleShape brawl_rect(sf::Vector2f(64, 64));										
		brawl_rect.setPosition(100, 100);
		
		
		//Archer background																			//Cannot get rectangle to appear on main menu screen. 
		sf::RectangleShape arch_rect(sf::Vector2f(64, 64));											//Use rectangle as background for sprite
		arch_rect.setPosition(375, 100);															//TODO: Get rectangle on screen and attach functions which would be similar to Brawler/Archer
	}

	void loadButton()
	{
		
		//Brawler Button
		if (BrawlerButton.loadFromFile("Brawler.png"))	//Displays PNG for Brawler
		{
			BrawlerButtonSprite.setTexture(BrawlerButton);
			BrawlerButtonSprite.setPosition(100, 200);
		}
		//Archer Button
		if (ArcherButton.loadFromFile("Archer.png"))
		{
			ArcherButtonSprite.setTexture(ArcherButton);
			ArcherButtonSprite.setPosition(300, 200);
		}

	}
	int returnData();
};

