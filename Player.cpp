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
