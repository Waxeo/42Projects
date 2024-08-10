#include "Zombie.Class.hpp"

Zombie* newZombie( std::string name )
{
    Zombie  *new_zombie = new Zombie(name);

    return new_zombie;
}