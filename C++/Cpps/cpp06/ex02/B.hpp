#ifndef B_HPP
# define B_HPP

#include <iostream>
#include <iomanip>
#include <string>

#include "Base.hpp"

class B : public Base
{
	public:
		B( void );
		~B( void );
};

std::ostream	&	operator<<( std::ostream & o, B const &rhs);

#endif