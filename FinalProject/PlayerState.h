#pragma once
#include "Playable_Character.h"
#include <SFML/Graphics.hpp>
class PlayerState
{
private:

public:
	virtual ~PlayerState();
	virtual void handleInput(Playable_Character& user);
	virtual void update(Playable_Character& user);
	

};

