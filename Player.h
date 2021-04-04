#pragma once

#include <unordered_map>
#include "Weapon.h"

class Player
{

public:

	Player();
	~Player();


	float getBalance();
	float setBalance(float balance);
	void AddWeapon(Weapon* weapon);
	std::unordered_map<int, Weapon*>& getWeaponList();



private:

	int m_numOfWeaponOwned;
	float m_balance;
	std::unordered_map<int, Weapon*> m_WeaponList;


};

