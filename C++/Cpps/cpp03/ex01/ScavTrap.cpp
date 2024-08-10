#include "ScavTrap.Class.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;

	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;

	return ;
}

ScavTrap::ScavTrap( ScavTrap &src )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_Name << " is dead." << std::endl; ;
		return ;
	}
	if (this->_EnergyPoints > 0)
	{
		std::cout << BLUE << "ScavTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << RESET << std::endl;
		this->_EnergyPoints--;
	}
	else
		std::cout << RED << "ScavTrap " << this->_Name << " needs energy to do an action" << RESET << std::endl;

	std::cout << this->_EnergyPoints << " Energy points remaining for " << this->_Name << std::endl;

	return ;
}

void ScavTrap::guardGate( void )
{
	std::cout << YELLOW << "ScavTrap is now in Gate keeper mode." << RESET << std::endl;
	return ;
}