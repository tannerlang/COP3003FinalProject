#ifndef NPC_ENEMY_H
#define NPC_ENEMY_H

#include "Character.h"
#include "Playable_Character.h"
#include "gameWorld.h"

class NPC_Enemy : public virtual Character
{

private:
	

public:
	
	NPC_Enemy();
	void initTexture();
	void initSprite();
	void set_Damage();
	void aggression();			//This is here for Boss & Skeleton
	void update(float spawnTimer, float spawnTimerMax);
	
};

#endif //!NPC_ENEMY_H