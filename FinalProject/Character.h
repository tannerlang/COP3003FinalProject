#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
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
	
	enum State{STATE_STANDING, STATE_MOVING, STATE_ATTACKING};
	State state_ = STATE_STANDING;

public:
	//members
	sf::Texture texture;
	sf::Sprite sprite;

	//methods
	Character();
	virtual ~Character();
	int get_Health();
	void set_Health(int h);
	void set_Movement_Speed(float x);
	float get_Movement_Speed();
	void update();
	void render(sf::RenderTarget& target);
	virtual bool isAlive();
	int getAttackDamage();
	void takeDamage(int damage);
	
	

};

