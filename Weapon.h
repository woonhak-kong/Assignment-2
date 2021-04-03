#pragma once

#include <iostream>


class Weapon
{
public:

	Weapon(std::string name, std::string soundString, int price);

	virtual ~Weapon() {};

	virtual bool IsBought();
	virtual std::string getName();
	virtual void SoundForUsing();
	virtual float getPrice();

	virtual void setBought(bool b);

protected:



private:

	bool m_bIsBought;
	int m_price;
	std::string m_name;
	std::string m_sound4using;
	int m_usedLater;


};

