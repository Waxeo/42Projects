#include "ClapTrap.Class.hpp"
#include "ScavTrap.Class.hpp"
#include "FragTrap.Class.hpp"


int main ( void )
{
    FragTrap first("Billy");
    FragTrap second("Bob");

    first.attack(second.getName());
    second.takeDamage(second.getDamage());

    second.beRepaired(1);

    first.highFivesGuys();
    
    return 0;
}
