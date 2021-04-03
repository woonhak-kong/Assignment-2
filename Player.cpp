#include "Player.h"

Player::Player():
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
