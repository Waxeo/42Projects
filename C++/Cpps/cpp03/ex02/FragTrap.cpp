#include "ClapTrap.Class.hpp"
#include "FragTrap.Class.hpp"
#include "ScavTrap.Class.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;

	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;

	return ;
}

FragTrap::FragTrap( FragTrap &src )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "FragTrap " << this->_Name << " is dead." << std::endl; ;
		return ;
	}
	if (this->_EnergyPoints > 0)
	{
		std::cout << BLUE << "FragTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << RESET << std::endl;
		this->_EnergyPoints--;
	}
	else
		std::cout << RED << "FragTrap " << this->_Name << " needs energy to do an action" << RESET << std::endl;

	std::cout << this->_EnergyPoints << " Energy points remaining for " << this->_Name << std::endl;

	return ;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << YELLOW << "FragTrap wants to high fives." << RESET << std::endl;
	return ;
}