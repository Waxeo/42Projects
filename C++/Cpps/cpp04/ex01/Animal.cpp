#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal( void )
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Animal::Animal( std::string type ) : _Type(type)
{
	std::cout << "Animal constructor called" << std::endl;
	return ;
}

Animal::Animal( const Animal &src )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Animal::~Animal( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Animal	&Animal::operator=( Animal const &src )
{
	// std::cout << "Assignement operator called" << std::endl;
	
	if ( this != &src )
		this->_Type = src._Type;

	return *this;
}

void	Animal::makeSound( void ) const

{
	std::cout << "oh jsuis bieng" << std::endl;

	return ;
}

std::string 	Animal::getType() const
{
	return this->_Type;
}

Brain*	Animal::getBrain() const
{
	return NULL;
}

void	Animal::setBrain(std::string idea)
{
	(void)idea;

	return ;
}