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
	MainMenu();
	virtual ~MainMenu();
	void MMrun();
	void MMupdate();
	void MMrender();
	bool boolOpen();
};

