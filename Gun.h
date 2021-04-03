#pragma once
#include "Weapon.h"
class Gun : public Weapon
{
public:

	Gun(std::string name, std::string soundString, int price);
	virtual ~Gun();



private:



};

