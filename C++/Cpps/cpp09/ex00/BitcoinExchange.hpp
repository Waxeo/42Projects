#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <map>
#include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[96m"

class BitcoinExchange
{
	public:
		BitcoinExchange( void );
		~BitcoinExchange( void );

		void	extractAndExec(char *fdsName);
		void	OutputManagement(std::string date, float value);

	private:
		BitcoinExchange( BitcoinExchange const &src );
		BitcoinExchange	&	operator=( BitcoinExchange const &rhs );


		std::map<std::string, float> _BitcoinData;


};

#endif