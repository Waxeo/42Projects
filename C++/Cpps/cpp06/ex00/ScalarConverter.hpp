#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <limits>

class ScalarConverter
{
	public:

		static void	convert(std::string base);
		
	private:

		ScalarConverter( void );
		ScalarConverter( ScalarConverter const &src );
		virtual ~ScalarConverter( void ) = 0;
		ScalarConverter	&	operator=( ScalarConverter const &rhs );
	
};

#endif