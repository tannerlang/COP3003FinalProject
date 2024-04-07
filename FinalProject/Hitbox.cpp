#include "Hitbox.h"
Hitbox::Hitbox(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height)
	:sprite(sprite), offsetX(offset_x), offsetY(offset_y)
{
	this->hitbox.setPosition(this->sprite.getPosition().x + offset_x, this->sprite.getPosition().y + offset_y);	//uses params to set hitbox positioin
	this->hitbox.setSize(sf::Vector2f(width, height));
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(1.f);
	this->hitbox.setOutlineColor(sf::Color::Green);	//for debugging on screen.
}

Hitbox::~Hitbox()
{

}

bool Hitbox::checkIntersect(const sf::FloatRect& frect)				//Function Objective: Check for collision/intersects
{
	return this->hitbox.getGlobalBounds().intersects(frect);
}

void Hitbox::update()
{
	this->hitbox.setPosition(this->sprite.getPosition().x + this->offsetX, this->sprite.getPosition().y + this->offsetY);			//updates hitbox position with position+offsets
}

void Hitbox::render(sf::RenderTarget& target)
{
	target.draw(this->hitbox);
}
