#pragma once
#include <SFML/Graphics.hpp>
#include"PlayerState.h"
#include<iostream>
class Character
{
private:
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
	int dexterity;	//attack-speed and crit
	
	



protected:
	sf::Texture texture;
	sf::Sprite sprite;

	//States
	PlayerState* PlayerState_;
	
	
public:
	enum State { STATE_STANDING, STATE_RUNNING, STATE_ATTACK, STATE_DODGE };
	State state_;
	Character();
	virtual ~Character();
	int get_Health();
	void set_Health(int h);
	void set_Movement_Speed(float x);
	float get_Movement_Speed();
	void update();
	void render(sf::RenderTarget& target);
	State getState_()
	{
		return state_;
	}
	

};

