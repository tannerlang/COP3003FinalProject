#ifndef SKELETON_H
#define SKELETON_H
#include "NPC_Enemy.h"

class Skeleton : public NPC_Enemy
{
public:

	Skeleton();
	~Skeleton();
	void initTexture();
	void initSprite();
	void set_Damage();
	void update(float spawnTimer, float spawnTimerMax);
	void moveSkeleton(const int dirX, const int dirY);
	void skeleton_Movement();
	void aggression(Playable_Character* user, Skeleton* entity, gameWorld gameWorld1);
	int getAttackDamage();
	void takeDamage(int damage);
};

#endif //!SKELETON_H