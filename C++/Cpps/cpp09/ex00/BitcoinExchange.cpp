#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
    //algo recuperation data.csv

    std::ifstream ifs;
    int           line = 0;
    ifs.open("data.csv");
    if (!ifs.is_open())
    {
        std::cout << "Failed to open the data file" << std::endl;
        return ;
    }

    std::string copy;

    while (std::getline(ifs, copy))
    {
    	if (line != 0)
		{
			std::size_t coma = copy.find(",");

			std::string date;
			float price = 0.0f;
			
  			if (coma != std::string::npos) 
			{
				date = copy.substr(0, coma);
				std::string value2 = copy.substr(coma + 1);
				price = static_cast<float>(std::atof(value2.c_str()));
			}

			this->_BitcoinData.insert(std::make_pair(date, price));
		}
        line++;
	}


    ifs.close();
    return ;
}

BitcoinExchange::~BitcoinExchange( void )
{
    return ;
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &src )
{
    *this = src;
    return ;
}

BitcoinExchange	&	BitcoinExchange::operator=( BitcoinExchange const &rhs )
{
	(void)rhs;
    return *this;
}


void	BitcoinExchange::extractAndExec(char *fdsName)
{
    std::ifstream ifs;
    int           line = 0;
    ifs.open(fdsName);
    if (!ifs.is_open())
    {
        std::cout << "Failed to open the input file" << std::endl;
        return ;
    }

    std::string copy;

    while (std::getline(ifs, copy))
    {		
    	if (line != 0)
		{
			std::size_t sep = copy.find("|");

			std::string date;
			float exchangeRate = 0.0f;

  			if (sep != std::string::npos) 
			{
				date = copy.substr(0, sep - 1);
				std::string value2 = copy.substr(sep + 2);
				if (value2.size() > 5)
        			std::cerr << "Exchange rate lower than 0 or higher than 1000." << std::endl;
				else
				{
					exchangeRate = static_cast<float>(std::atof(value2.c_str()));
					this->OutputManagement(date, exchangeRate);
				}
				// if (!isdigit(value2))
					// throw badvalueexception
				
			}
			if (sep == std::string::npos)
        		std::cerr << "Problem in input file." << std::endl;
		}
        line++;
	}

    ifs.close();
    return ;
}

void	BitcoinExchange::OutputManagement(std::string date, float value)
{
	std::string year;
	std::string month;
	std::string day;

	// std::cout << "date = " << date << std::endl;

	year = date.substr(0, 4);
	month = date.substr(5, 2);
	day = date.substr(8, 2);

	// std::cout << "year = " << year << std::endl;
	// std::cout << "month = " << month << std::endl;
	// std::cout << "day = " << day << std::endl;

	
	//gestion annee
	int test = std::atoi(year.c_str());
	// std::cout << test << std::endl;
	if (test < 2009 || test > 2025)
	{
        std::cerr << "Bad date input." << std::endl;
		return ;
	}

	//gestion mois
	int test2 = std::atoi(month.c_str());
	// std::cout << test2 << std::endl;
	if (test2 < 1 || test2 > 12)
	{
        std::cerr << "Bad date input." << std::endl;
		return ;
	}

	//gestion jours
	int test3 = std::atoi(day.c_str());
	// std::cout << test3 << std::endl;
	if (test3 < 1 || test3 > 31)
	{
        std::cerr << "Bad date input." << std::endl;
		return ;
	}

	//gestion mois en 31 / 30 jours + gestion annee bissextille pour fevrier 
	if (test2 == 4 || test2 == 6 || test2 == 9 || test2 == 11)
	{
		if (test3 > 30)
		{
			std::cerr << "Bad date input." << std::endl;
			return ;
		}
	}
	else if (test2 == 2)
	{
		if (test % 4 != 0)
		{
			if (test3 > 28)
			{
				std::cerr << "Bad date input." << std::endl;
				return ;
			}
		}
		else
		{
			if (test % 100 == 0 && test % 400 != 0)
			{
				if (test3 > 28)
				{
					std::cerr << "Bad date input." << std::endl;
					return ;
				}
			}
			else
			{
				if (test3 > 29)
				{
					std::cerr << "Bad date input." << std::endl;
					return ;
				}
			}
		}
	}	

	if (value < 0 || value > 1000)
	{
        std::cerr << "Exchange rate lower than 0 or higher than 1000." << std::endl;
		return ;
	}

    std::map<std::string, float>::iterator it = this->_BitcoinData.lower_bound(date);

    if (it == this->_BitcoinData.begin())
	{
        std::cerr << "There is no data before 2009-01-02." << std::endl;
        return ;
    }
	else if (it == this->_BitcoinData.end())
        --it;
	else 
	{
        if (it->first != date && it != this->_BitcoinData.begin())
            --it;
    }

	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}


/*	DEBUG
	for (std::map<std::string, float>::iterator it = this->_BitcoinData.begin(); it != this->_BitcoinData.end(); ++it) {

		std::cout << "Première variable : " << it->first << std::endl;

		std::cout << "Deuxième variable : " << it->second << std::endl;

		// Passage au maillon suivant
		std::cout << std::endl;  
    }
*/