#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "default cat constructor called" << std::endl;

	return ;
}

Cat::Cat( std::string name ) : Animal(name)
{
	std::cout << "Cat constructor called" << std::endl;

	return ;
}

Cat::Cat( const Cat &src ) : Animal(src._Type)
{
	// std::cout << "Copy constructor called" << std::endl;

	return ;
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

Cat	&Cat::operator=( Cat const &src )
{
	this->_Type = src._Type;
	
	return *this;
}

void	Cat::makeSound( void ) const
{
	std::cout << "MiaouMiaou" << std::endl;

	return ;
}