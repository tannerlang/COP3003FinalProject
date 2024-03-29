#pragma once
#include <SFML/Graphics.hpp>
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
	




	
public:
	Character();
	virtual ~Character();
	int get_Health();
	void set_Health(int h);
	void set_Movement_Speed(float x);
	float get_Movement_Speed();
	void update();
	void render(sf::RenderTarget& target);
	


};

