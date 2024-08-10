#include "Zombie.Class.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde = new Zombie[N]; // Alloue un tableau de N objets Zombie

    for (int i = 0; i < N; i++)
        horde[i].assign_name(name); // Initialise chaque objet Zombie avec le nom donné

    return horde;
}

