#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[5;96m"

class Base
{
	public:
		virtual ~Base( void );
};

#endif
