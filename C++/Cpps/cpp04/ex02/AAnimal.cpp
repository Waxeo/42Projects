#include "AAnimal.hpp"
#include "Brain.hpp"

AAnimal::AAnimal( void )
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal( std::string type ) : _Type(type)
{
	std::cout << "AAnimal constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal( const AAnimal &src )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

AAnimal::~AAnimal( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

AAnimal	&AAnimal::operator=( AAnimal const &src )
{
	// std::cout << "Assignement operator called" << std::endl;
	
	if ( this != &src )
		this->_Type = src._Type;

	return *this;
}

void	AAnimal::makeSound( void ) const

{
	std::cout << "oh jsuis bieng" << std::endl;

	return ;
}

std::string 	AAnimal::getType() const
{
	return this->_Type;
}

Brain*	AAnimal::getBrain() const
{
	return NULL;
}

void	AAnimal::setBrain(std::string idea)
{
	(void)idea;

	return ;
}