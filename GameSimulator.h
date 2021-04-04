#pragma once

#include <Windows.h>




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
	void ShowGameUI();
	void PrintSquare(COORD position);

private:

	const COORD Q_PLACE = { 10, 2 };
	const COORD W_PLACE = { 20, 2 };
	const COORD E_PLACE = { 30, 2 };
	const COORD R_PLACE = { 40, 2 };
	const COORD F_PLACE = { 50, 2 };



	HANDLE m_windowsHandle;

};

