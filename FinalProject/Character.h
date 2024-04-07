#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Hitbox.h"

class Character
{
private:


protected:
	//core stats
	int health;
	int max_health;
	int level;
	int exp;
	int max_stamina;
	int stamina;
	int damage;
	bool dodge;
	int speed;
	int attack_speed;
	float crit_chance;
	float movementSpeed;

	//attributes
	int vitality;	//health and stamina
	int strength;	//damage
	int agility;	//dodge and speed
	int dexterity;	//attack-speed and c
	
	enum State { STATE_STANDING, STATE_MOVING, STATE_ATTACKING };
	State state_ = STATE_STANDING;
	

public:
	
	//members
	sf::Texture texture;
	sf::Sprite sprite;

	//methods
	Hitbox* hitbox;
	Character();
	virtual ~Character();
	int get_Health();
	void set_Health(int h);
	void set_Movement_Speed(float x);
	float get_Movement_Speed();
	void update();
	void render(sf::RenderTarget* target);
	virtual bool isAlive();
	virtual int getAttackDamage();
	virtual void takeDamage(int damage);
	void createHitbox(sf::Sprite& sprite, const float offset_x, const float offset_y, float width, float height);
	virtual void set_Damage();
	int getState()
	{
		return state_;
	}

};

