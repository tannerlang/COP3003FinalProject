#ifndef NPC_ENEMY_H
#define NPC_ENEMY_H

#include "Character.h"
class NPC_Enemy : public Character
{

private:
	

public:
	
	NPC_Enemy();
	void initTexture();
	void initSprite();
	void set_Damage();
	
};

#endif //!NPC_ENEMY_H