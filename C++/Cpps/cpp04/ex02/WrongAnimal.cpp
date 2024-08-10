#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( std::string type ) : _Type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal &src )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const &src )
{
	// std::cout << "Assignement operator called" << std::endl;
	
	if ( this != &src )
		this->_Type = src._Type;

	return *this;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "oh jsuis pas bieng" << std::endl;

	return ;
}

std::string 	WrongAnimal::getType() const
{
	return this->_Type;
}