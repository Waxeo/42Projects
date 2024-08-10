#include "ClapTrap.Class.hpp"

ClapTrap::ClapTrap( void )
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap &src )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=( ClapTrap const &src )
{
	// std::cout << "Assignement operator called" << std::endl;
	
	if ( this != &src )
	{
		this->_Name = src._Name;
		this->_HitPoints = src._HitPoints;
		this->_EnergyPoints = src._EnergyPoints;
		this->_AttackDamage = src._AttackDamage;
	}

	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "Claptrap " << this->_Name << " is dead." << std::endl; ;
		return ;
	}
	if (this->_EnergyPoints > 0)
	{
		std::cout << BLUE << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << RESET << std::endl;
		this->_EnergyPoints--;
	}
	else
		std::cout << RED << "ClapTrap " << this->_Name << " needs energy to do an action" << RESET << std::endl;

	std::cout << this->_EnergyPoints << " Energy points remaining for " << this->_Name << std::endl;

	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "Claptrap " << this->_Name << " is already dead" << std::endl; ;
		return ;
	}
	this->_HitPoints -= amount;

	std::cout << this->_HitPoints << " Health points remaining for " << this->_Name << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "Claptrap " << this->_Name << " is dead." << std::endl;
		return ;
	}
	if (this->_EnergyPoints > 0)
	{
		this->_HitPoints += amount;
		std::cout << GREEN << "ClapTrap " << this->_Name << " repared " << amount << " Health points" << RESET << std::endl;
		this->_EnergyPoints--;
	}
	else
		std::cout << RED << "ClapTrap " << this->_Name << " needs energy to do an action" << RESET << std::endl;

	std::cout << this->_HitPoints << " Health points remaining for " << this->_Name << std::endl;

	return ;
}

std::string		ClapTrap::getName( void )
{
	return this->_Name;
}

int		ClapTrap::getDamage( void )
{
	return this->_AttackDamage;
}

