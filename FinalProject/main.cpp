#include<SFML/Graphics.hpp>
#include "gameWorld.h"
#include "gameTile.h"
#include"Brawler.h"
#include"game.h"
int main()
{
	Game PlayGame;
	PlayGame.run();

		//TODO:figure out how to have class selection so that in the game class files we are not just calling brawler, we need to be able to call archer too and it be dynamic.
		//do we have to create a hybid inheritance class that derives from Brawler and Archer? 
}
