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
	

public:
	sf::Text ChooseCharacter;
	sf::Font arial;
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
};

