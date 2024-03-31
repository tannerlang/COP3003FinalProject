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
			mousPos = sf::Mouse::getPosition();
			///Exit
			if (event.type == sf::Event::Closed)
			{
				this->MMwindow->close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//Brawler Button
				if (mousPos.x >= 125 && mousPos.x <= 189 && mousPos.y >= 100 && mousPos.y <= 164)				//trying to get the MMwindow to close when mouse clicks where the sprite is.
				{
				
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

