#ifndef EASYFIND_HPP
# define EASYFIND_HPP

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

class NoOccurenceFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "No occurence find";
		}
};

template <typename T>
void	easyfind(T Container, int to_find)
{
	typename T::const_iterator  finder = std::find(Container.begin(), Container.end(), to_find);

	if (finder != Container.end())
	{
		typename T::const_iterator  begin = Container.begin();

		std::cout << "occurence find at index : " << std::distance(begin, finder)  << std::endl;
	}
	else
		throw NoOccurenceFoundException();
	return ;
}

#endif