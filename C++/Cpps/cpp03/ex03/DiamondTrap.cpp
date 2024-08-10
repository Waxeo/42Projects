#include "ClapTrap.Class.hpp"
#include "FragTrap.Class.hpp"
#include "ScavTrap.Class.hpp"
#include "DiamondTrap.Class.hpp"

DiamondTrap::DiamondTrap( void ) : ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	
	return ;
}

DiamondTrap::DiamondTrap( std::string name ) :  ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;

	this->_Name = name;
	this->_HitPoints = FragTrap::_HitPoints;
	this->_EnergyPoints = ScavTrap::_EnergyPoints;
	this->_AttackDamage = FragTrap::_AttackDamage;

	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap &src )
{
	*this = src;

	return ;
}


DiamondTrap::~DiamondTrap( void )
{
	std::cout << RED << std::endl << "DiamondTrap destructor called" << RESET << std::endl;
	return ;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);

	return ;
}

std::string		DiamondTrap::getName( void )
{
	return this->_Name;
}

int		DiamondTrap::getHitPoints( void )
{
	return this->_HitPoints;
}

int		DiamondTrap::getEnergyPoints( void )
{
	return this->_EnergyPoints;
}

int		DiamondTrap::getDamage( void )
{
	return this->_AttackDamage;
}

void DiamondTrap::whoAmI( void )
{
	std::cout << GREEN << "DiamondTrap name is "<< this->_Name << " whereas ClavTrap name is " << ClapTrap::_Name << RESET << std::endl;

	return ;
}
