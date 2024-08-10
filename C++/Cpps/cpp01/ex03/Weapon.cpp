#include "Weapon.Class.hpp"

Weapon::Weapon(std::string Type) : _type(Type)
{
    return ;
}

Weapon::~Weapon()
{
    return ;
}

const std::string	&Weapon::getType( void )  
{
    return this->_type;
}

void    Weapon::setType(std::string Type)
{
    this->_type = Type;

    return ;
}