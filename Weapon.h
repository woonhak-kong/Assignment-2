#pragma once

#include <iostream>


class Weapon
{
public:

	Weapon(std::string name, std::string soundString);
	virtual ~Weapon() {};

	virtual bool IsOwned();
	virtual std::string getName();
	virtual void SoundForUsing();

protected:



private:

	bool m_bIsOwned;
	std::string m_name;
	std::string m_sound4using;
	int m_usedLater;


};

