#include "MainMenu.h"
MainMenu::MainMenu()
{
	this->MMinitWindow();
}

MainMenu::~MainMenu()
{
	delete this->MMwindow;
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
		}
		this->MMrender();
	}
}

void MainMenu::MMrender()
{
	this->MMwindow->clear();

	//drawing stuff here

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