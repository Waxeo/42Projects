#include "Zombie.Class.hpp"

int main()
{
    Zombie  *horde = zombieHorde(3, "Robert");

    for (int i = 0; i < 3; i++)
        horde[i].announce();

    delete [] horde;


    Zombie  *horde2 = zombieHorde(5, "Lewis");

     for (int i = 0; i < 5; i++)
        horde2[i].announce();

    delete [] horde2;

    return (0);
}