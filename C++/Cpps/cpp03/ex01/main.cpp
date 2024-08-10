#include "ScavTrap.Class.hpp"

int main ( void )
{
    ScavTrap first("Billy");
    ScavTrap second("Bob");

    first.attack(second.getName());
    second.takeDamage(second.getDamage());

    second.beRepaired(1);

    first.guardGate();
    
    return 0;
}
