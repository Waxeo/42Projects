#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <stack>
#include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[96m"

class RPN
{
	public:

        RPN( char *operation );
		~RPN( void );

        void    stack_management( std::string to_add );
        void    operation( std::string ope );

        class Lessthan2numbersException : public std::exception
		{
    		public:
       			virtual const char* what() const throw();
		};

        class NumbersleftinstackException : public std::exception
		{
    		public:
       			virtual const char* what() const throw();
		};
        
        class BadcharException : public std::exception
		{
    		public:
       			virtual const char* what() const throw();
		};
        
        class TwodigitnumberException : public std::exception
		{
    		public:
       			virtual const char* what() const throw();
		};

	private:

		RPN( void );
		RPN( RPN const &src );
		RPN	&	operator=( RPN const &rhs );

		std::stack<int, std::deque<int> > _calcul;
};

#endif