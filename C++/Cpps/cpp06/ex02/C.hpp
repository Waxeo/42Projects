#ifndef C_HPP
# define C_HPP

#include <iostream>
#include <iomanip>
#include <string>

#include "Base.hpp"

class C : public Base
{
	public:
		C( void );
		~C( void );
};

std::ostream	&	operator<<( std::ostream & o, C const &rhs);

#endif