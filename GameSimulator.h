#pragma once

#include <Windows.h>
#include "Player.h"




class GameSimulator
{
private:
	enum class COLOR
	{
		GREEN = 10,
		CYAN = 11,
		RED = 12,
		PINK = 13,
		YELLOW = 14,
		WHITE = 15
	};

public:
	GameSimulator();
	~GameSimulator();

	void Start();



private:

	void ChangeCC(COLOR color);
	void ChangeCursorPlace(int x, int y);
	void ShowGameUI(Player player);
	void PrintSquare(COORD position);
	void ShowPlayerItem(Player player);

private:

	const COORD Q_PLACE = { 10, 2 };
	const COORD W_PLACE = { 32, 2 };
	const COORD E_PLACE = { 54, 2 };
	const COORD R_PLACE = { 76, 2 };
	const COORD F_PLACE = { 76, 6 };
	const COORD ITEM_SHWING_PLACE = { 120, 6 };


	const COORD Q_NAME_PLACE = { Q_PLACE.X + 2, Q_PLACE.Y + 1 };
	const COORD W_NAME_PLACE = { W_PLACE.X + 2, W_PLACE.Y + 1 };
	const COORD E_NAME_PLACE = { E_PLACE.X + 2, E_PLACE.Y + 1 };
	const COORD R_NAME_PLACE = { R_PLACE.X + 2, R_PLACE.Y + 1 };
	const COORD F_NAME_PLACE = { F_PLACE.X + 2, F_PLACE.Y + 1 };



	HANDLE m_windowsHandle;

};

