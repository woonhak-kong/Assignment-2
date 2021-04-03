#pragma once


#include "Player.h"

class Store
{
public:

	Store();
	~Store();

	void EnterStore(Player& player);


private:

	int m_currentState;

private:

	void PrintMenu();
	void ShowPlayerBalance(Player& player) const;


};

