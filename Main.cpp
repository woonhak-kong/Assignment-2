#include <iostream>
#include "Store.h"
#include "Player.h"



int main()
{
	Store* store = new Store();
	Player player;

	store->EnterStore(player);
	delete store;





	return 0;
}