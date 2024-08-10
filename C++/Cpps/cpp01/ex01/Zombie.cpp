#include "Zombie.Class.hpp"

Zombie::Zombie()
{
    return ;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " went back to earth" << std::endl;

    return ;
}

void    Zombie::assign_name(std::string name)
{
    this->_name = name;
}

void    Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;

    return ;
}