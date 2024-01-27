#pragma once
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

	//attributes
	int vitality;	//health and stamina
	int strength;	//damage
	int agility;	//dodge and speed
	int dexterity;	//attack-speed and crit
	




	
public:
	Character();
	~Character();
	int get_Health();
	void set_Health(int h);


};

