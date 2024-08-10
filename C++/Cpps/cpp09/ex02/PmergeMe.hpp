#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[1;96m"
#define WHITE_BOLD "\033[1;97m"


class PmergeMe
{
	
	public:

		PmergeMe(int ac, char **av);
		~PmergeMe();

		void	check_double();

		void	sortVector();
		void	sortFirst(std::vector<int> &first, std::vector<int> &second);
		void	mergeAll(std::vector<int> &first, std::vector<int> &second);

		void	sortList();
		void	sortFirstL(std::list<int> &first, std::list<int> &second);
		void	mergeAllL(std::list<int> &first, std::list<int> &second);

		void	affVector();
		void	affList();

		std::vector<int>::iterator getBegin();
		std::vector<int>::iterator getEnd();

		std::list<int>::iterator getLBegin();
		std::list<int>::iterator getLEnd();

		class DoubledNbException : public std::exception
		{
    		public:
       			virtual const char* what() const throw();
		};

		class ErrorInParsingException : public std::exception
		{
    		public:
       			virtual const char* what() const throw();
		};

	private:

		std::vector<int> _MyVector;
		
		std::vector<int>::iterator _itef;
		std::vector<int>::iterator _ites;

		std::list<int> _MyList;
		
		std::list<int>::iterator _Litef;
		std::list<int>::iterator _Lites;

};

std::ostream	&	operator<<( std::ostream & o, PmergeMe &rhs);






#endif

// en gros division par recursion jusqua avoir des paires.
// tu mets les plus gros de chaques paires dun coté de la paire. 
// ensuite tu sépares en deux liste avec les plus gros dun coté
// et les plus petits de lautres. les plus gros doivent etre trié
// dans lordre. ensuite en utilisant la suite de jacobstahl tu
// fais un binary un sort



// 2 vector, on met dans le premier 