#include "Zombie.Class.hpp"

int main()
{
    Zombie  *Bobby = newZombie( "Bobby" );

    randomChump( "Scooby" );

    Bobby->announce();

    delete Bobby;

    return (0);
}