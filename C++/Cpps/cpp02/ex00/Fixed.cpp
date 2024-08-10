#include "Fixed.Class.hpp"

Fixed::Fixed( void ) : _Nb(0)
{
	std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed( Fixed const &src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

    return ;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;

    return ;
}

Fixed	&	Fixed::operator=( Fixed const &rhs )
{
	std::cout << "Assignement operator called" << std::endl;
	
	if ( this != &rhs )
		this->_Nb = rhs.getRawBits();

	return *this;
}


int Fixed::getRawBits( void ) const
{
	std::cout << "Geter called" << std::endl;

	return this->_Nb;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "Seter called" << std::endl;

	this->_Nb = raw;

	return ;
}