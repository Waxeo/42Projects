#include "A.hpp"

A::A( void ) : Base()
{
	std::cout << "A constructor called" << std::endl;
	return ;
}

A::~A( void )
{
	std::cout << "A destructor called" << std::endl;
	return ;
}

std::ostream	&	operator<<( std::ostream & o, A const &rhs)
{
	(void)rhs;
	o << "This class is identified as A class." << std::endl;

	return o;
}