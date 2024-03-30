#include "gameWorld.h"

gameWorld::gameWorld() 
{
	gridLength = 31;
	gridHeight = 17 ;                       //what does this do, should it be bigger since we scaled the window up?
	this->setUpInitialState();
}


void gameWorld::setUpInitialState() 
{
	exitPos = sf::Vector2i(1,0);													//creates the exit positon vector with eleements
	playerPos = sf::Vector2i(gridLength - 1, gridHeight - 1);						//creates the player position, subtracts from gridlength/height by 1 for the xand y coords

	setUpTiles();
	setUpEnemyPositions();
	
}


void gameWorld::setUpEnemyPositions() 
{
	enemyPositions.clear();
	enemyPositions.push_back(sf::Vector2i(0, 2));
	enemyPositions.push_back(sf::Vector2i(6, 2));
	enemyPositions.push_back(sf::Vector2i(2, 7));					//places enemies is their enemyPositons vector
}

void gameWorld::setUpTiles()									//populates tiles vector
{
	tiles.clear();
	std::vector<gameTile*>tileRow;								/*creates a vector of gameTile objects called tileRow.(creates texture and sprite in that location if it can load)
																  This is the inner vector object that popultes each tiles vector (columns)*/
	float y = 0;
	for (int row = 0; row <= 16; row++)
	{
		float x = 0;

		for (int column = 0; column <= 30; column++)
		{
			tileRow.push_back(new gameTile("plains.png", x, y, true, true));		/*populates that location with a new gameTile object which places a sprite
																						at position (x,y)*/		
			x += 64;
		}																					
		y += 64;
		tiles.push_back(tileRow);															//creates a new row (tiles is outer vector which is rows)							
	}																						//nested forlopp populates map with spritre in sf::window
}
