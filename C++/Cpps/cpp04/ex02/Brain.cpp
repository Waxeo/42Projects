#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "default brain constructor called" << std::endl;
	
	return ;
}

Brain::Brain( Brain &src )
{
	// std::cout << "brain's copy constructor called" << std::endl;

	*this = src;

	return ;
}

Brain::~Brain( void )
{
	std::cout << "brain destructor called" << std::endl;

	return ;
}

Brain	&Brain::operator=( Brain const &src )
{
	// std::cout << "brain assignement operator called" << std::endl;

	for (int i = 0; i < 100; i++)
		this->_Ideas[i] = src._Ideas[i];

	return *this;
}

void	Brain::getIdeas()
{
	for (int i = 0; i <= 10; i++)
		std::cout << this->_Ideas[i] << std::endl;

	return ;
}

void	Brain::setIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->_Ideas[i] = idea;

	return ;
}
