#include "gameWorld.h"


gameWorld::gameWorld() {
	gridLength = 8;
	setUpInitialState();
}


void gameWorld::setUpInitialState() {
	exitPos = sf::Vector2i(1,0);
	playerPos = sf::Vector2i(gridLength - 1, gridLength - 1);
	setUpEnemyPositions();
	setUpTiles();

}


void gameWorld::setUpEnemyPositions() {
	enemyPositions.clear();
	enemyPositions.push_back(sf::Vector2i(0, 2));
	enemyPositions.push_back(sf::Vector2i(6, 2));
	enemyPositions.push_back(sf::Vector2i(2, 7));
}


void gameWorld::setUpTiles() {
	tiles.clear();
	std::vector<gameTile*>firstRow;
	firstRow.push_back(new gameTile("wall.png", 0, 0, false, false));
	firstRow.push_back(new gameTile("plains.png", 50, 0, true, true));
	firstRow.push_back(new gameTile("wall.png", 100, 0, false, false));
	firstRow.push_back(new gameTile("wall.png", 150, 0, false, false));
	firstRow.push_back(new gameTile("wall.png", 200, 0, false, false)); 
	firstRow.push_back(new gameTile("wall.png", 250, 0, false, false));
	firstRow.push_back(new gameTile("enemy.png", 300, 0, true, false));
	firstRow.push_back(new gameTile("plains.png", 350, 0, false, false));
	tiles.push_back(firstRow);

	std::vector<gameTile*>secondRow;
	secondRow.push_back(new gameTile("wall.png", 0, 50, false, false));
	secondRow.push_back(new gameTile("plains.png", 50, 50, true, false));
	secondRow.push_back(new gameTile("plains.png", 100, 50, true, false));
	secondRow.push_back(new gameTile("plains.png", 150, 50, true, false));
	secondRow.push_back(new gameTile("plains.png", 200, 50, true, false));
	secondRow.push_back(new gameTile("plains.png", 250, 50, true, false));
	secondRow.push_back(new gameTile("plains.png", 300, 50, true, false));
	secondRow.push_back(new gameTile("plains.png", 350, 50, true, false));
	tiles.push_back(secondRow);

	std::vector<gameTile*>thirdRow;
	thirdRow.push_back(new gameTile("wall.png", 0, 100, false, false));
	thirdRow.push_back(new gameTile("plains.png", 50, 100, true, false));
	thirdRow.push_back(new gameTile("plains.png", 100, 100, true, false));
	thirdRow.push_back(new gameTile("plains.png", 150, 100, false, false));
	thirdRow.push_back(new gameTile("plains.png", 200, 100, true, false));
	thirdRow.push_back(new gameTile("plains.png", 250, 100, true, false));
	thirdRow.push_back(new gameTile("plains.png", 300, 100, false, false));
	thirdRow.push_back(new gameTile("plains.png", 350, 100, false, false));
	tiles.push_back(thirdRow);

	std::vector<gameTile*>fourthRow;
	fourthRow.push_back(new gameTile("wall.png", 0, 150, false, false));
	fourthRow.push_back(new gameTile("plains.png", 50, 150, true, false));
	fourthRow.push_back(new gameTile("plains.png", 100, 150, true, false));
	fourthRow.push_back(new gameTile("plains.png", 150, 150, false, false));
	fourthRow.push_back(new gameTile("plains.png", 200, 150, true, false));
	fourthRow.push_back(new gameTile("plains.png", 250, 150, true, false));
	fourthRow.push_back(new gameTile("plains.png", 300, 150, true, false));
	fourthRow.push_back(new gameTile("plains.png", 350, 150, false, false));
	tiles.push_back(fourthRow);

	std::vector<gameTile*>fifthRow;
	fifthRow.push_back(new gameTile("wall.png", 0, 200, false, false));
	fifthRow.push_back(new gameTile("plains.png", 50, 200, true, false));
	fifthRow.push_back(new gameTile("plains.png", 100, 200, true, false));
	fifthRow.push_back(new gameTile("plains.png", 150, 200,false, false));
	fifthRow.push_back(new gameTile("plains.png", 200, 200, false, false));
	fifthRow.push_back(new gameTile("plains.png", 250, 200, true, false));
	fifthRow.push_back(new gameTile("plains.png", 300, 200, true, false));
	fifthRow.push_back(new gameTile("plains.png", 350, 200, true, false));
	tiles.push_back(fifthRow);

	std::vector<gameTile*>sixthRow;
	sixthRow.push_back(new gameTile("wall.png", 0, 250, true, false));
	sixthRow.push_back(new gameTile("plains.png", 50, 250, true, false));
	sixthRow.push_back(new gameTile("plains.png", 100, 250, true, false));
	sixthRow.push_back(new gameTile("plains.png", 150, 250, true, false));
	sixthRow.push_back(new gameTile("plains.png", 200, 250, false, false));
	sixthRow.push_back(new gameTile("plains.png", 250, 250, true, false));
	sixthRow.push_back(new gameTile("plains.png", 300, 250, true, false));
	sixthRow.push_back(new gameTile("plains.png", 350, 250, false, false));
	tiles.push_back(sixthRow);

	std::vector<gameTile*>seventhRow;
	seventhRow.push_back(new gameTile("wall.png", 0, 300, false, false));
	seventhRow.push_back(new gameTile("plains.png", 50, 300, false, false));
	seventhRow.push_back(new gameTile("plains.png", 100, 300, true, false));
	seventhRow.push_back(new gameTile("plains.png", 150, 300, true, false));
	seventhRow.push_back(new gameTile("plains.png", 200, 300, true, false));
	seventhRow.push_back(new gameTile("plains.png", 250, 300, true, false));
	seventhRow.push_back(new gameTile("plains.png", 300, 300, true, false));
	seventhRow.push_back(new gameTile("plains.png", 350, 300, false, false));
	tiles.push_back(seventhRow);

	std::vector<gameTile*>eigthRow;
	eigthRow.push_back(new gameTile("wall.png", 0, 350, false, false));
	eigthRow.push_back(new gameTile("plains.png", 50, 350, false, false));
	eigthRow.push_back(new gameTile("plains.png", 100, 350, true, false));
	eigthRow.push_back(new gameTile("plains.png", 150, 350, false, false));
	eigthRow.push_back(new gameTile("plains.png", 200, 350, false, false));
	eigthRow.push_back(new gameTile("plains.png", 250, 350, true, false));
	eigthRow.push_back(new gameTile("plains.png", 300, 350, true, false));
	eigthRow.push_back(new gameTile("plains.png", 350, 350, true, false));
	tiles.push_back(eigthRow);

}