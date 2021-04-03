#include "Gun.h"

Gun::Gun(std::string name, std::string soundString, int price):
    Weapon::Weapon(name, soundString, price)
{
}

Gun::~Gun()
{
}
