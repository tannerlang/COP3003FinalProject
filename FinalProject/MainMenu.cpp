#include "MainMenu.h"
MainMenu::MainMenu()
{
	this->loadText();
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
		}
		this->MMrender();
	}
}

void MainMenu::MMrender()
{
	this->MMwindow->clear();
	
	
	//drawing stuff here
	
	this->MMwindow->draw(ChooseCharacter);
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



//---------------Brawler Button-----------------
/*
class BrawlerButton 
{
private:
	sf::Sprite normal;
	sf::Sprite clicked;
	sf::Sprite* currentSpr;
	sf::String String;
	bool current;
public:
	BrawlerButton(sf::Image* normal, sf::Image* clicked, std::string, sf::Vector2f location)
	{
		(sf::Image * normal, sf::Image * clicked, std::string words, sf::Vector2f location) ;
	{
		this->normal.SetImage(*normal);
		this->clicked.SetImage(*clicked);
		this->currentSpr = &this->normal;
		current = false;
		this->normal.SetPosition(location);
		this->clicked.SetPosition(location);
		String.SetText(words);
		String.SetPosition(location.x + 3, location.y + 3);
		String.SetSize(14);
	}
	}
	void checkClick(sf::Vector2f)
	{
		if (mousePos.x > currentSpr->GetPosition().x && mousePos.x < (currentSpr->GetPosition().x + currentSpr->GetSize().x)) {
			if (mousePos.y > currentSpr->GetPosition().y && mousePos.y < (currentSpr->GetPosition().y + currentSpr->GetSize().y)) {
				setState(!current);
			}
		}
	}
}
	void setState(bool)
	{
		current = which;
		if (current) {
			currentSpr = &clicked;
			return;
		}
		currentSpr = &normal;
	}
	void setText(std::string)
	{
		String.SetText(words);
	}

	bool getVar()
	{
		return current;
	}

	sf::Sprite* getSprite()
	{
		return currentSpr;
	}
	sf::String* getText()
	{
		return &String;
	}
};
*/