#include "ClapTrap.Class.hpp"
#include "ScavTrap.Class.hpp"
#include "FragTrap.Class.hpp"
#include "DiamondTrap.Class.hpp"

int        main(void) 
{ 
	DiamondTrap        tic("Monstre");
	std::cout << std::endl;
	DiamondTrap        tic2("Double Monstre");
	std::cout << std::endl;

	std::cout << CYAN << "tic2 first name = " << tic2.getName() << RESET << std::endl;

	tic2 = tic; 
	DiamondTrap        tic3(tic);

	std::cout << CYAN << std::endl << tic3.getName() << RESET << std::endl << std::endl;

	tic3.whoAmI();

	std::cout << tic2.getName() << std::endl << tic2.getHitPoints() << std::endl\
	<< tic2.getEnergyPoints() << std::endl << tic2.getDamage()  << std::endl << std::endl;

	tic2.attack(tic.getName());
	
	return (0); 
}