#pragma once
#include "Playable_Character.h"
class Brawler : public virtual Playable_Character
{

private:
   

public:
    Brawler();
    void initTexture();
    void initSprite();
    void initText();
    void handleInput(Playable_Character* user);
    void attack();
    int getAttackDamage();
    void set_Damage();
    void takeDamage(int damage);
};

