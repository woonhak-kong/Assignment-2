#include "Player.h"

Player::Player():
	m_numOfWeaponOwned(0),
	m_balance(10000)
{
}

Player::~Player()
{
}

float Player::getBalance()
{
	return m_balance;
}

float Player::setBalance(float balance)
{
	return m_balance = balance;
}

void Player::AddWeapon(Weapon* weapon)
{
	m_WeaponList.insert(std::unordered_map<int, Weapon*>::value_type(++m_numOfWeaponOwned, weapon));
}

std::unordered_map<int, Weapon*>& Player::getWeaponList()
{
	return m_WeaponList;
}

std::unordered_map<Player::EQUIP_PLACE, Weapon*>& Player::getEquippedWeaponList()
{
	return m_EquippedWeaponList;
}

bool Player::EquipWeapon(EQUIP_PLACE place, Weapon* weapon)
{


	if (!weapon->IsBought())
	{
		auto tmpWeapon = m_EquippedWeaponList.find(place);
		// if there is not empty
		if (tmpWeapon != m_EquippedWeaponList.end())
		{
			tmpWeapon->second->setBought(false);
			m_EquippedWeaponList.erase(place);
		}
		m_EquippedWeaponList[place] = weapon;
		weapon->setBought(true);
		return true;
	}
	else
	{
		return false;

	}

}

bool Player::UseWeapon(EQUIP_PLACE place)
{
	auto tmpWeapon = m_EquippedWeaponList.find(place);
	if (tmpWeapon != m_EquippedWeaponList.end())
	{
		tmpWeapon->second->SoundForUsing();
		return true;
	}
	else
	{
		return false;
	}
}
