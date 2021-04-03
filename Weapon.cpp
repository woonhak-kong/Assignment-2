#include "Weapon.h"

Weapon::Weapon(std::string name, std::string soundString, int price):
	m_bIsBought(false),
	m_price(price),
	m_name(name),
	m_sound4using(soundString),
	m_usedLater(0)
{
}

bool Weapon::IsBought()
{
	return m_bIsBought;
}

std::string Weapon::getName()
{
	return m_name;
}

void Weapon::SoundForUsing()
{
	std::cout << m_sound4using << std::endl;
}

float Weapon::getPrice()
{
	return m_price;
}

void Weapon::setBought(bool b)
{
	m_bIsBought = b;
}
