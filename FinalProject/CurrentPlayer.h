#pragma once
#include "Brawler.h"
#include "Archer.h"
class CurrentPlayer :	public Brawler, public Archer				//TODO: Make constructors in base classes to use here, incorporate movement functions and use this as main class for init
{

public:
	CurrentPlayer();			//How can we determine which character to choose? Maybe a boolean brawler(0) and archer (1)


};

