#include "Store.h"
#include <iostream>
#include <iomanip>

using namespace std;

Store::Store():
	m_currentState(0)
{
}

Store::~Store()
{
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
			cout << "Thanks. Bye!\n";
			cout << "Enter please.......";
			cin.get();
			cin.get();
		}
		else if (select == 1)
		{

			cin.get();
			cin.get();
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

void Store::PrintMenu()
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
