#pragma once
#include "Weapon.h"
class Sword : public Weapon
{

public:

	Sword(std::string name, std::string soundString);


	bool IsOwned() override;
	std::string getName() override;
	void SoundForUsing() override;


private:

};

