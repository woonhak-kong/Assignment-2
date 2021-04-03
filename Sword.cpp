#include "Sword.h"

Sword::Sword(std::string name, std::string soundString, int price):
    Weapon::Weapon(name, soundString, price)
{
}

Sword::~Sword()
{
}
