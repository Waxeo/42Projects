#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <vector>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[96m"

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin( void ){return this->c.begin();}
		iterator end( void ){return this->c.end();}
};


#endif