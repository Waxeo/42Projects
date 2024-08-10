#include "HumanA.Class.hpp"

HumanA::HumanA(std::string Name, Weapon &Weapon) : _name(Name), _weapon(Weapon)
{
    return ;
}

HumanA::~HumanA()
{
    return ;
}

void    HumanA::attack( void )
{
    std::cout << RED << this->_name << " attacks with their " << this->_weapon.getType() << RESET << std::endl;

    return ;
}
