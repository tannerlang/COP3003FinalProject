#pragma once
#include "Brawler.h"
#include "Archer.h"
class CurrentPlayer :	public Brawler, public Archer				//TODO: Make constructors in base classes to use here, incorporate movement functions and use this as main class for init
{

public:
	CurrentPlayer(const std::string PlayerClass);			//How can we determine which character to choose? Maybe a boolean brawler(0) and archer (1)
																//when creating object make do it with constructor called to be able to choose what you pass to decide which class you are playing

};

