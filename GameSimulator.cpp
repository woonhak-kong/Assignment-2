#include "GameSimulator.h"
#include "Store.h"
#include "Player.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

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




	ChangeCC(COLOR::WHITE);
	//ShowPlayerEquippedWeapon(player);
	do
	{
		string select;
		int tmpLine = 10;


		ShowGameUI(player);



		ChangeCursorPlace(Q_PLACE.X, Q_PLACE.Y + tmpLine++);
		cout << "Choose your weapon to equip on right side by typing number";
		ChangeCursorPlace(Q_PLACE.X, Q_PLACE.Y + tmpLine++);
		cout << "Or type character (q, w, e, r, f) for using";
		ChangeCursorPlace(Q_PLACE.X, Q_PLACE.Y + tmpLine++);
		cout << "> ";
		getline(cin, select);
		//cin.get();

		int selectToInt = 0;
		if (atoi(select.c_str()) != 0)
		{
			selectToInt = atoi(select.c_str());
		}


		cout << selectToInt;

		if (select == "q" || select == "w" || select == "e" || select == "r" || select == "f")
		{
			if (select == "q")
			{
				player.UseWeapon(Player::EQUIP_PLACE::Q);
			}
			else if (select == "w")
			{
				player.UseWeapon(Player::EQUIP_PLACE::W);
			}
			else if (select == "e")
			{
				player.UseWeapon(Player::EQUIP_PLACE::E);
			}
			else if (select == "r")
			{
				player.UseWeapon(Player::EQUIP_PLACE::R);
			}
			else if (select == "f")
			{
				player.UseWeapon(Player::EQUIP_PLACE::F);
			}

		}
		else if (selectToInt > player.getWeaponList().size() || selectToInt < 1)
		{
			ChangeCursorPlace(Q_PLACE.X, Q_PLACE.Y + tmpLine++);
			cout << "Please Type Correct Number!!";
			ChangeCursorPlace(Q_PLACE.X, Q_PLACE.Y + tmpLine++);
			cout << "Enter please...";
			cin.get();

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10, '\n');
				cin.get();
				//cin.get();
			}

		}
		else
		{
			char tmpPlace;

			ChangeCursorPlace(Q_PLACE.X, Q_PLACE.Y + tmpLine++);
			cout << "You select [" << player.getWeaponList().at(selectToInt)->getName() << "].";
			ChangeCursorPlace(Q_PLACE.X, Q_PLACE.Y + tmpLine++);
			cout << "What Place (q,w,e,r,f) Do You Equip This?";
			ChangeCursorPlace(Q_PLACE.X, Q_PLACE.Y + tmpLine++);
			cin >> tmpPlace;
			cin.get();

			if (tmpPlace == 'q' || tmpPlace == 'w' || tmpPlace == 'e' || tmpPlace == 'r' || tmpPlace == 'f')
			{

				switch (tmpPlace)
				{
					case 'q':
						player.EquipWeapon(Player::EQUIP_PLACE::Q, player.getWeaponList().at(selectToInt));
						break;
					case 'w':
						player.EquipWeapon(Player::EQUIP_PLACE::W, player.getWeaponList().at(selectToInt));
						break;
					case 'e':
						player.EquipWeapon(Player::EQUIP_PLACE::E, player.getWeaponList().at(selectToInt));
						break;
					case 'r':
						player.EquipWeapon(Player::EQUIP_PLACE::R, player.getWeaponList().at(selectToInt));
						break;
					case 'f':
						player.EquipWeapon(Player::EQUIP_PLACE::F, player.getWeaponList().at(selectToInt));
						break;
					default:
						break;
				}

			}
			else
			{
				ChangeCursorPlace(Q_PLACE.X, Q_PLACE.Y + tmpLine++);
				cout << "Please Type Correct Character!!";
				ChangeCursorPlace(Q_PLACE.X, Q_PLACE.Y + tmpLine++);
				cout << "Enter please...";
				cin.get();
			}


		}

		system("cls");
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

	ShowPlayerEquippedWeapon(player);


	//ChangeCursorPlace(1, 30);
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

void GameSimulator::ShowPlayerEquippedWeapon(Player player)
{
	auto equippedList = player.getEquippedWeaponList();

	for (auto iter = equippedList.begin(); iter != equippedList.end(); iter++)
	{
		switch ((*iter).first)
		{
			case Player::EQUIP_PLACE::Q:
				SetPlaceWithWeapon(Q_NAME_PLACE,(*iter).second);
				break;
			case Player::EQUIP_PLACE::W:
				SetPlaceWithWeapon(W_NAME_PLACE, (*iter).second);
				break;
			case Player::EQUIP_PLACE::E:
				SetPlaceWithWeapon(E_NAME_PLACE, (*iter).second);
				break;
			case Player::EQUIP_PLACE::R:
				SetPlaceWithWeapon(R_NAME_PLACE, (*iter).second);
				break;
			case Player::EQUIP_PLACE::F:
				SetPlaceWithWeapon(F_NAME_PLACE, (*iter).second);
				break;
			default:
				break;
		}
	}
}

void GameSimulator::SetPlaceWithWeapon(COORD position, Weapon* weapon)
{
	ChangeCC(COLOR::GREEN);
	ChangeCursorPlace(position.X, position.Y);
	cout << weapon->getName();
	ChangeCC(COLOR::WHITE);
}