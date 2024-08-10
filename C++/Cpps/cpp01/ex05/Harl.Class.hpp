#ifndef HARL_CLASS_HPP
# define HARL_CLASS_HPP

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

class Harl
{
    private:
		void _debug( void );
		void _info( void );
		void _warning( void );
		void _error( void );
    public:
        Harl( void );
        ~Harl( void );
		void complain( std::string level );
        
};

#endif