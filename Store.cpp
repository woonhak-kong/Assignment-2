#include "Store.h"
#include <iostream>
#include <iomanip>
#include "Sword.h"
#include "Gun.h"
#include "Wand.h"
#include <Windows.h>

using namespace std;

Store::Store():
	m_currentState(0)
{
	InitStore();
}

Store::~Store()
{
	for (auto iter = m_WeaponList.begin(); iter != m_WeaponList.end(); iter++)
	{
		delete iter->second;
	}
	m_WeaponList.clear();
}

void Store::EnterStore(Player& player)
{
	int select;
	do
	{
		PrintMenu();
		cin >> select;
		cout << endl;

		if (select == 3)
		{
			if (player.getWeaponList().size() < 1)
			{
				select = -1;
				cout << "You cannot go out of this store without buying!!\n";
				cout << "You must buy at least one thing. HAHAHAHAHAHA\n";
				cout << "Enter please.......";
				cin.get();
				cin.get();
			}
			else
			{
				cout << "Thanks. Bye!\n";
				cout << "Enter please.......";
				cin.get();
				cin.get();
			}
		}
		else if (select == 1)
		{
			system("cls");
			EnterBuyingWeapon(player);
		}
		else if (select == 2)
		{
			ShowPlayerBalance(player);
		}
		else if (select < 1 || select > 2)
		{
			cout << "Please Type (1 - 3) Please....\n";
			cin.get();
			cin.get();
		}

		system("cls");

	} while (select != 3);



}

void Store::InitStore()
{
	m_WeaponList.insert(std::unordered_map<int, Weapon*>::value_type(1, new Sword("Dragon_Slayer", "Kill the Dragon!!", 1000)));
	m_WeaponList.insert(std::unordered_map<int, Weapon*>::value_type(2, new Sword("Excalibur", "Excalibur!!!!!", 2000)));
	m_WeaponList.insert(std::unordered_map<int, Weapon*>::value_type(3, new Sword("Storm_Blinger", "Lighting!!", 1500)));
	m_WeaponList.insert(std::unordered_map<int, Weapon*>::value_type(4, new Sword("Asura", "Asura Pa Chun Mu!!", 5000)));
	m_WeaponList.insert(std::unordered_map<int, Weapon*>::value_type(5, new Gun("Flamethrower", "Phu~~~~~~~~~", 1000)));
	m_WeaponList.insert(std::unordered_map<int, Weapon*>::value_type(6, new Gun("Shot_Gun", "Shot!!", 1500)));
	m_WeaponList.insert(std::unordered_map<int, Weapon*>::value_type(7, new Gun("Pistol", "Bang!!", 500)));
	m_WeaponList.insert(std::unordered_map<int, Weapon*>::value_type(8, new Gun("Sniper", "Slient kill!!", 2000)));
	m_WeaponList.insert(std::unordered_map<int, Weapon*>::value_type(9, new Wand("Ice_Wand", "Fire Ball!!", 2000)));
	m_WeaponList.insert(std::unordered_map<int, Weapon*>::value_type(10, new Wand("Fire_Wand", "Ice Ball!!", 2000)));
}

void Store::PrintMenu() const
{
	cout << "|     Choose One     |\n";
	cout << "|====================|\n";
	cout << "| 1. Buy Weapon      |\n";
	cout << "| 2. Check Balance   |\n";
	cout << "| 3. Exit Store      |\n";
	cout << "|====================|\n";
	cout << "> ";
}

void Store::ShowPlayerBalance(Player& player) const
{
	system("cls");
	cout << showpoint << fixed << setprecision(2);
	cout << "|       Balance      |\n";
	cout << "|====================|\n";
	cout << "| $ " << setw(17) << left << player.getBalance() << "|\n";
	cout << "|====================|\n\n";

	cout << "Enter please.......\n";
	cin.get();
	cin.get();

}

void Store::ShowWeapons() const
{
	cout << fixed << showpoint << setprecision(2);
	cout << "|     Select Number you want to buy      |\n";
	cout << "|========================================|\n";
	for (auto iter = m_WeaponList.begin(); iter != m_WeaponList.end(); iter++)
	{
		cout << "| " << setw(2)<<left << iter->first << ". " << setw(21) << left << iter->second->getName();
		cout << "| $ " << setw(10) << left << iter->second->getPrice() << "|" << std::endl;
	}
	cout << "|========================================|\n";
	cout << "| 0. Back                                |\n";
	cout << "> ";
}

void Store::EnterBuyingWeapon(Player& player) const
{
	int select = 0;;

	do
	{
		cout << showpoint << fixed << setprecision(2);
		cout << "|============ Your Balance ==============|\n";
		cout << "| $ " << setw(37) << left << player.getBalance() << "|\n";
		cout << "|========================================|\n";
		ShowWeapons();
		cin >> select;


		if (select == 0)
		{
		}
		else if (select > m_WeaponList.size() || select < 1)
		{
			cout << "Please Correct Number Please....\n";
			cin.get();
			cin.get();
		}
		else
		{
			auto weapon = m_WeaponList.at(select);
			if (!weapon->IsBought())
			{
				if (player.getBalance() - weapon->getPrice() < 0)
				{
					cout << "You don't have enough money!!\n";
					cout << "Enter please.......";
					cin.get();
					cin.get();
				}
				else
				{
					// Just use defalut copy constructor because Weapon doesn't have any pointers.
					player.AddWeapon(new Weapon(*(weapon)));
					player.setBalance(player.getBalance() - weapon->getPrice());
					cout << "You bought [" << weapon->getName() << "]\n";
					cout << "Enter please.......";
					cin.get();
					cin.get();
					weapon->setBought(true);
				}
			}
			else
			{
				cout << "You Already Have This Item\n";
				cout << "Enter please.......";
				cin.get();
				cin.get();
			}
		}
		system("cls");

	} while (select != 0);
}


