#pragma once


#include "Player.h"
#include <string>
#include <map>
#include "Weapon.h"
#include <unordered_map>

class Store
{
public:

	Store();
	~Store();

	void EnterStore(Player& player);


private:

	int m_currentState;
	std::unordered_map<int, Weapon*> m_WeaponList;


private:

	void InitStore();
	void PrintMenu() const;
	void ShowPlayerBalance(Player& player) const;
	void ShowWeapons() const;
	void EnterBuyingWeapon(Player& player) const;


};

