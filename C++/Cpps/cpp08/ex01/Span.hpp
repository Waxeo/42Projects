#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[96m"

class Span
{
	public:
		Span( void );
		Span( unsigned int n );
		Span( Span const &src);
		~Span( void );

		void	addNumber(int to_add);
		int	shortestSpan( void );
		int	longestSpan( void );

		void	addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, std::vector<int> numbers);

		class SpanAlreadyFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
	private:
		unsigned int _N;
		std::vector<int> _Array;

};

#endif