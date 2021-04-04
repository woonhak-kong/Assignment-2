#include "GameSimulator.h"
#include "Store.h"
#include "Player.h"
#include <iostream>

using namespace std;

GameSimulator::GameSimulator()
{
	system("mode con cols=150 lines=40");
	m_windowsHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

GameSimulator::~GameSimulator()
{
}

void GameSimulator::Start()
{
	//Store* store = new Store();
	//Player player;
	//store->EnterStore(player);
	//delete store;

	ShowGameUI();

}

void GameSimulator::ChangeCC(COLOR color)
{
	SetConsoleTextAttribute(m_windowsHandle, static_cast<int>(color));
}

void GameSimulator::ChangeCursorPlace(int x , int y)
{
	COORD tmp;
	tmp.X = x;
	tmp.Y = y;
	SetConsoleCursorPosition(m_windowsHandle, tmp);
}

void GameSimulator::ShowGameUI()
{
	PrintSquare(Q_PLACE);

}

void GameSimulator::PrintSquare(COORD position)
{
	ChangeCursorPlace(position.X, position.Y);
	cout << "====================\n";
	ChangeCursorPlace(position.X, position.Y+2);
	cout << "====================\n";
}
