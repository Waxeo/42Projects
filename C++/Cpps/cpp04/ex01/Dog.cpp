#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	std::cout << "default dog constructor called" << std::endl;

	this->_Brain = new Brain();

	return ;
}

Dog::Dog( std::string type ) : Animal(type)
{
	std::cout << "Dog constructor called" << std::endl;

	this->_Brain = new Brain();
	
	return ;
}

Dog::Dog( const Dog &src ) : Animal(src)
{
	// std::cout << "Copy constructor called" << std::endl;
	
	this->_Brain = new Brain(*src._Brain);

	return ;
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called" << std::endl;

	delete this->_Brain;
	
	return ;
}

Dog	&Dog::operator=( Dog const &src )
{	
	if (this != &src)
	{
		this->_Type = src._Type;
		
		delete this->_Brain;
		this->_Brain = new Brain(*src._Brain);
	}

	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "WafWaf" << std::endl;

	return ;
}

Brain*	Dog::getBrain() const
{
	return _Brain;
}

void	Dog::setBrain(std::string idea)
{
	this->_Brain->setIdeas(idea);

	return ;
}