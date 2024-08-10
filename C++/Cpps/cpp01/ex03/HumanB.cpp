#include "HumanB.Class.hpp"

HumanB::HumanB(std::string Name) : _name(Name)
{
	this->_weapon = NULL;

	return ;
}

HumanB::~HumanB()
{
	return ;
}

void    HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;

	return ;
}


void    HumanB::attack( void )
{
	if (!this->_weapon)
		std::cout << BLUE << this->_name << " attacks with their legs" << RESET << std::endl;
	else 
		std::cout << BLUE << this->_name << " attacks with their " << this->_weapon->getType() << RESET << std::endl;

	return ;
}
