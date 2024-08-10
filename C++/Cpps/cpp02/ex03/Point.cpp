#include "Point.Class.hpp"

Point::Point( void ) : _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::endl;
    return ;
}

Point::Point( const float X, const float Y ) : _x(X), _y(Y)
{
	// std::cout << "Float constructor called" << std::endl;
    return ;
}

Point::Point( Point const &src )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;

    return ;
}

Point::~Point( void )
{
	// std::cout << "Destructor called" << std::endl;

    return ;
}

Point	&	Point::operator=( Point const &src ) 
{
	// std::cout << "Assignement operator called" << std::endl;
	
	if ( this != &src )
    {
		(Fixed) this->_x = src._x;
		(Fixed) this->_y = src._y;
    }

	return *this;
}

float Point::getX( void ) const
{
	return this->_x.toFloat();
}

float Point::getY( void ) const
{
	return this->_y.toFloat();
}

void Point::setX( Fixed vec )
{
	std::cout << "vec = " << vec << std::endl;
	(Fixed) this->_x = vec;
	std::cout << "x = " << this->_x << std::endl;
	return ;
}

void Point::setY( Fixed vec )
{
	(Fixed) this->_y = vec;
	return ;
}
