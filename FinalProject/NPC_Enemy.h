#ifndef NPC_ENEMY_H
#define NPC_ENEMY_H

#include "Character.h"
class NPC_Enemy : public Character
{

private:
	

public:
	NPC_Enemy(float posX, float posY);
	void initTexture();
	void initSprite();
	void set_Damage();

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif //!NPC_ENEMY_H