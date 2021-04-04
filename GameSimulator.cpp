#include "GameSimulator.h"
#include "Store.h"
#include "Player.h"
#include <iostream>
#include <iomanip>

#include "Gun.h"
#include "Sword.h"
#include "Wand.h"

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
	Player player;
	//store->EnterStore(player);
	//delete store;

	player.AddWeapon(new Sword("Dragon_Slayer", "Kill the Dragon!!", 1000));
	player.AddWeapon(new Sword("Excalibur", "Excalibur!!!!!", 2000));
	player.AddWeapon(new Sword("Storm_Blinger", "Lighting!!", 1500));
	player.AddWeapon(new Sword("Asura", "Asura Pa Chun Mu!!", 5000));
	player.AddWeapon(new Gun("Flamethrower", "phu~~~~~~~~~", 1000));
	player.AddWeapon(new Gun("Shot_Gun", "Shot!!", 1500));
	player.AddWeapon(new Gun("Pistol", "Bang!!", 500));
	player.AddWeapon(new Gun("Sniper", "slient kill!!", 2000));
	player.AddWeapon(new Wand("Ice_Wand", "Fire Ball!!", 2000));
	player.AddWeapon(new Wand("Fire_Wand", "Ice Ball!!", 2000));

	ShowGameUI(player);


	ChangeCC(COLOR::WHITE);
	int select = 0;

	do
	{
		ChangeCursorPlace(Q_PLACE.X, Q_PLACE.Y + 10);
		cout << "Choose your weapon on right side by type number";
		ChangeCursorPlace(Q_PLACE.X, Q_PLACE.Y + 11);
		cout << "> ";
		cin >> select;

	} while (true);



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

void GameSimulator::ShowGameUI(Player player)
{
	ChangeCC(COLOR::YELLOW);
	PrintSquare(Q_PLACE);
	PrintSquare(W_PLACE);
	PrintSquare(E_PLACE);
	PrintSquare(R_PLACE);
	PrintSquare(F_PLACE);
	ChangeCC(COLOR::CYAN);
	ChangeCursorPlace(Q_PLACE.X + 4, Q_PLACE.Y - 1);
	cout << "    [Q]";
	ChangeCursorPlace(W_PLACE.X + 4, W_PLACE.Y - 1);
	cout << "    [W]";
	ChangeCursorPlace(E_PLACE.X + 4, E_PLACE.Y - 1);
	cout << "    [E]";
	ChangeCursorPlace(R_PLACE.X + 4, R_PLACE.Y - 1);
	cout << "    [R]";
	ChangeCursorPlace(F_PLACE.X + 4, F_PLACE.Y - 1);
	cout << "    [F]";
	ChangeCC(COLOR::WHITE);



	ShowPlayerItem(player);


	ChangeCursorPlace(1, 30);
}

void GameSimulator::PrintSquare(COORD position)
{
	ChangeCursorPlace(position.X, position.Y);
	cout << "O------------------O";
	ChangeCursorPlace(position.X, position.Y + 1);
	cout << "|                  |";
	ChangeCursorPlace(position.X, position.Y + 2);
	cout << "O------------------O";
}

void GameSimulator::ShowPlayerItem(Player player)
{


	ChangeCC(COLOR::CYAN);
	ChangeCursorPlace(ITEM_SHWING_PLACE.X, ITEM_SHWING_PLACE.Y - 1);
	cout << "     [YOUR WEAPONS]";

	ChangeCC(COLOR::YELLOW);
	ChangeCursorPlace(ITEM_SHWING_PLACE.X, ITEM_SHWING_PLACE.Y);
	cout << "O----------------------O";
	int i = 1;
	for (; i <= player.getWeaponList().size() * 2; i++)
	{
		ChangeCursorPlace(ITEM_SHWING_PLACE.X, ITEM_SHWING_PLACE.Y + i );
		cout << "|                      |";
	}
	ChangeCursorPlace(ITEM_SHWING_PLACE.X, ITEM_SHWING_PLACE.Y + i);
	cout << "O----------------------O";


	for (auto iter = player.getWeaponList().begin(); iter != player.getWeaponList().end(); iter++)
	{
		ChangeCursorPlace(ITEM_SHWING_PLACE.X + 2, (ITEM_SHWING_PLACE.Y - 1) + (*iter).first * 2);
		ChangeCC(COLOR::RED);
		cout << setw(2) << left <<(*iter).first << ". ";
		ChangeCC(COLOR::GREEN);
		cout << (*iter).second->getName();
	}

	//for (i = 0; i < player.getWeaponList().size(); i++)
	//{
	//	ChangeCursorPlace(ITEM_SHWING_PLACE.X, ITEM_SHWING_PLACE.Y + i * 2);
	//	cout << player.getWeaponList()[i+1]->getName();
	//}


}
