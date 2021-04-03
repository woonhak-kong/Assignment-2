#include "Weapon.h"

Weapon::Weapon(std::string name, std::string soundString):
	m_bIsOwned(false),
	m_name(name),
	m_sound4using(soundString),
	m_usedLater(0)
{
}

bool Weapon::IsOwned()
{
	return m_bIsOwned;
}

std::string Weapon::getName()
{
	return m_name;
}

void Weapon::SoundForUsing()
{
	std::cout << m_sound4using << std::endl;
}
