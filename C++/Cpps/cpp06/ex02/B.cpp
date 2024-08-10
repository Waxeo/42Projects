#include "B.hpp"

B::B( void )
{
	std::cout << "B constructor called" << std::endl;
	return ;
}

B::~B( void )
{
	std::cout << "B destructor called" << std::endl;
	return ;
}

std::ostream	&	operator<<( std::ostream & o, B const &rhs)
{
	(void)rhs;
	o << "This class is identified as B class." << std::endl;

	return o;
}