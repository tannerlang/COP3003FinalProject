#include <SFML/Graphics.hpp>
#include "gameWorld.h"
#include "gameTile.h"
#include "Brawler.h"
#include "game.h"
int main()
{
	//Init srand
	std::srand(static_cast<unsigned>(time(NULL)));

	Game PlayGame;
	PlayGame.run();

		/*TODO: Make display widget to select character before the game starts.
		^ongoing solve how to get data from button click to the factory as the enum code. (PlayerClassID) I think this is why its not selecting the correct character.


		i am starting to see what is happening. It isnt every displaying the brawler sprite. In the situation where it is displaing the cutoff sprite, that is actually the archer sprite
		so it never is building a brawler. I switched the brawler sprite image in for the archer class as a check and it displays it fine. So the issue isnt with the sprites it is with the code.
		This makes me think it is an error in the factory function. Or a fix may be to take the initsprite and texture functions in the archer and brawler classes and have them be made in the dummy class 
		and have it build the correct sprite based on the PlayerID value that comes through to tell the factory function.
		
		!!OR!!

		(this angle should be taken first)
		the issue is simply with the PlayerID data isnt correctly making its way from the main menu class and into the factory function called through selectCharacter() in game.cpp
		currently trying to mess with pointers with PlayerID from main menu

		*/
		
}
