#include "MainMenu.h"
MainMenu::MainMenu()
{
	this->loadText();
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
			///Exit
			if (event.type == sf::Event::Closed)
			{
				this->MMwindow->close();
			}
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				mousPos = sf::Mouse::getPosition();
				if (mousPos.x == BrawlerButtonPos.x && mousPos.y == BrawlerButtonPos.y)
				{
					PlayerClassID = 0;
				}
			}
			
		}
		this->MMrender();
		BrawlerButtonPos = BrawlerButtonSprite.getPosition();//the position of the button
		
		BrawlerButtonSize = BrawlerButtonSprite.getScale();//the size of the button
		
		
		
	}
}

void MainMenu::MMrender()
{
	this->MMwindow->clear();
	
	
	//drawing stuff here
	
	this->MMwindow->draw(ChooseCharacter);
	this->MMwindow->draw(BrawlerButtonSprite);
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
	return 0;
}

