#include "C.hpp"

C::C( void )
{
	std::cout << "C constructor called" << std::endl;
	return ;
}

C::~C( void )
{
	std::cout << "C destructor called" << std::endl;
	return ;
}

std::ostream	&	operator<<( std::ostream & o, C const &rhs)
{
	(void)rhs;
	o << "This class is identified as C class." << std::endl;

	return o;
}