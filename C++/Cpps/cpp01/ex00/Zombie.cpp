#include "Zombie.Class.hpp"

Zombie::Zombie(std::string Zname) : _name(Zname)
{
    return ;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " went back to earth" << std::endl;

    return ;
}

void    Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;

    return ;
}