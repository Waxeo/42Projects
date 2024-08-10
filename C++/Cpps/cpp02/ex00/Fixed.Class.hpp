#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[5;96m"

class Fixed
{
	public:

		Fixed( void );
		Fixed( Fixed const &src );
		~Fixed( void );

		Fixed	&	operator=( Fixed const &rhs );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:

		int	_Nb;
		const	static	int	_BitsNb = 8;

};

#endif