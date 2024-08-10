#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "default cat constructor called" << std::endl;

	this->_Brain = new Brain();

	return ;
}

Cat::Cat( std::string name ) : Animal(name)
{
	std::cout << "Cat constructor called" << std::endl;

	this->_Brain = new Brain();

	return ;
}

Cat::Cat( const Cat &src ) : Animal(src)
{
	// std::cout << "Copy constructor called" << std::endl;
	
	this->_Brain = new Brain(*src._Brain);

	return ;
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called" << std::endl;

	delete this->_Brain;

	return ;
}

Cat	&Cat::operator=( Cat const &src )
{

	// std::cout << "Cat Assignement operator called" << std::endl;

	if (this != &src)
	{
		this->_Type = src._Type;

		delete this->_Brain;
		this->_Brain = new Brain(*src._Brain);
	}
	
	return *this;
}

void	Cat::makeSound( void ) const
{
	std::cout << "MiaouMiaou" << std::endl;

	return ;
}

Brain*	Cat::getBrain() const
{
	return _Brain;
}

void	Cat::setBrain(std::string idea)
{
	this->_Brain->setIdeas(idea);

	return ;
}