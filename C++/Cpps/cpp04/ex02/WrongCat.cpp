#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	std::cout << "default Wrongcat constructor called" << std::endl;

	return ;
}

WrongCat::WrongCat( std::string name ) : WrongAnimal(name)
{
	std::cout << "WrongCat constructor called" << std::endl;

	return ;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=( WrongCat const &src )
{
	this->_Type = src._Type;
	
	return *this;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "wakawakahehe" << std::endl;

	return ;
}