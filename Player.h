#pragma once

#include <unordered_map>
#include "Weapon.h"

class Player
{



public:

	enum class EQUIP_PLACE
	{
		Q = 0,
		W,
		E,
		R,
		F
	};


	Player();
	~Player();


	float getBalance();
	float setBalance(float balance);
	void AddWeapon(Weapon* weapon);
	std::unordered_map<int, Weapon*>& getWeaponList();
	std::unordered_map<EQUIP_PLACE, Weapon*>& getEquippedWeaponList();

	bool EquipWeapon(EQUIP_PLACE place, Weapon* weapon);
	bool UseWeapon(EQUIP_PLACE place);



private:

	int m_numOfWeaponOwned;
	float m_balance;
	std::unordered_map<int, Weapon*> m_WeaponList;
	std::unordered_map<EQUIP_PLACE, Weapon*> m_EquippedWeaponList;


};

