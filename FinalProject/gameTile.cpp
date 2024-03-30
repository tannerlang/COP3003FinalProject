#include "gameTile.h"

gameTile::gameTile(std::string textureName, float x, float y, bool passable, bool exit) {

	if (!setUpSprite(textureName)) {
		return;
	}
	pos = sf::Vector2f(x, y);					//creates a 2d vector called pos, x and y are passed from gameWorld forloop which is where the next tile will be
	sprite.setPosition(pos);					//sets the position of the sprite to position of pos (passed variable from tile vector in forloop)

	isPassable = passable;						//Allows sprite to walk over tile
	isExit = exit;								//Creates an exit point 
}


bool gameTile::setUpSprite(std::string textureName) {							//Produces error code if PNG doesn't load
	if (!texture.loadFromFile(textureName)) {							
		return false;
	}
	texture.setSmooth(true);													//if the texture can load
	sprite.setTexture(texture);													//set the texture to whatever is passed
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));							//set 64 pixels x 64 pixel size
	return true;
}