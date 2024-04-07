#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include"SFML\Graphics.hpp"
#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Audio.hpp"

class Hitbox
{
private:
	

public:
	sf::Sprite& sprite;			//forces a sprite
	sf::RectangleShape hitbox;
	float offsetX;
	float offsetY;
	Hitbox(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);				//params to set offset from position of sprite. Have to force sprite
	virtual ~Hitbox();

	//function
	bool checkIntersect(const sf::FloatRect& frect);

	void update();
	void render(sf::RenderTarget& target);
};

