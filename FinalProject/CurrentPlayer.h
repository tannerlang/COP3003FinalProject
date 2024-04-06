#pragma once
#include "Brawler.h"
#include "Archer.h"
#include <memory>
#include <iostream>

class CurrentPlayer : public Brawler, public Archer
{
private:
	
public:

	//factory function picks which opject to create and returns a ptr to new object created
	Playable_Character* factory(PlayerClassID id)
	{
		if (id == Brawl)
		{
			return new Brawler();
		}
		else if (id == Arch)
		{
			return new Archer();							//fix is here, 
		}
		else
		{
			return nullptr;
		}
	}

	virtual ~CurrentPlayer() = default;



								//need to build a "factory" to build
								//A factory is a function that takes a set of arguments indicating what to build, and returns an instance of what needed building.
								//https://www.geeksforgeeks.org/factory-method-for-designing-pattern/
};

