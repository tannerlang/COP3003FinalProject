#include "MainMenu.h"
MainMenu::MainMenu()
{
	this->loadText();
	this->rect();
	this->loadButton();
	this->MMinitWindow();
}

MainMenu::~MainMenu()
{
	//send data of selected character to game class in here?
}
void MainMenu::MMinitWindow()
{
	this->MMwindow = new sf::RenderWindow(sf::VideoMode(MMwindowWidth, MMwindowHeight), "Select A Character");
	this->MMwindow->setFramerateLimit(240);
	this->MMwindow->setVerticalSyncEnabled(false);
}

void MainMenu::MMrun()
{
	while (this->MMwindow->isOpen())
	{
		this->MMupdate();
	}
}

void MainMenu::MMupdate()
{
	while (this->MMwindow->isOpen())
	{
		sf::Event event;
		while (this->MMwindow->pollEvent(event))
		{															
			mousPos = sf::Mouse::getPosition();						//This might have some insight on the issue
																	//https://stackoverflow.com/questions/10962270/mouse-position-and-click-detect-in-sfml
			///Exit
			if (event.type == sf::Event::Closed)
			{
				this->MMwindow->close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//Brawler Button													
				if (mousPos.x = BrawlerButtonSprite.getPosition().x /* && mousPos.y == BrawlerButtonSprite.getPosition().y*/)				//Temp solution. Able to click anywhere on screen to initiate game. 
				{																															//Blocked code was an attempt to cooridinate the postion for click but seems to be an issue with comparing vect float to vect int
				
					PlayerClassID = 0;
					this->MMwindow->close();
				}
				//Archer Button
				if (true)
				{
					//PlayerClassID = 1;
					//this->MMwindow->close();
				}
			}
		}
		this->MMrender();
	}
}

void MainMenu::MMrender()
{
	this->MMwindow->clear();
	
	
	//drawing stuff here
	
	this->MMwindow->draw(ChooseCharacter);
	this->MMwindow->draw(BrawlerButtonSprite);
	this->MMwindow->draw(rectangle);				//This may be lingering issue with drawing rectangle
	this->MMwindow->display();
}

bool MainMenu::boolOpen()
{
	if (this->MMwindow->isOpen())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int MainMenu::returnData()
{
	return PlayerClassID;
}

