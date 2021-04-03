#include "Sword.h"

Sword::Sword(std::string name, std::string soundString):
    Weapon(name, soundString)
{
}

bool Sword::IsOwned()
{
    return Weapon::IsOwned();
}

std::string Sword::getName()
{
    return Weapon::getName();
}

void Sword::SoundForUsing()
{
    Weapon::SoundForUsing();
}
