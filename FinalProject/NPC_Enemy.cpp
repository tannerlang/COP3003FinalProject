#include "NPC_Enemy.h"

NPC_Enemy::NPC_Enemy(float posX, float posY)
{
	this->initTexture();
	this->initSprite();
	
};



//Public functions
void NPC_Enemy::initTexture()
{
	if (!this->texture.loadFromFile("NPC_Enemy.png")) //upload PNG of the enemy
	{
		std::cout << "Texture Load Failure";
	}
}

void NPC_Enemy::initSprite()
{
	//set texture to sprite
	this->sprite.setTexture(this->texture);
}

void NPC_Enemy::update()
{

}

void NPC_Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

