#ifndef A_HPP
# define A_HPP

#include <iostream>
#include <iomanip>
#include <string>

#include "Base.hpp"

class A : public Base
{
	public:
		A( void );
		~A( void );
};

std::ostream	&	operator<<( std::ostream & o, A const &rhs);


#endif
