#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	if (ac < 2)
		throw ErrorInParsingException();

	
	for (int i = 1; i < ac; i++)
	{
		int j = 0;
		while (av[i][j])
		{
			if (!isdigit(av[i][j]))
				throw ErrorInParsingException();
			j++;
		}

		if (strlen(av[i]) > 11)
			throw ErrorInParsingException();
		unsigned long long parse = std::atoi(av[i]);
		if (parse > 2147483646)
			throw ErrorInParsingException();

		_MyVector.push_back(std::atoi(av[i]));
		_MyList.push_back(std::atoi(av[i]));
	}
	check_double();

	std::cout << RED << "Before: ";
	for (std::vector<int>::iterator  it = getBegin(); it != getEnd(); it++)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;

	return ;
}

PmergeMe::~PmergeMe()
{
	return ;
}

void	PmergeMe::check_double()
{
	std::vector<int>::iterator check = _MyVector.begin();
	std::vector<int>::iterator finder = check;

	while (check != _MyVector.end())
	{
		finder = check;
		finder++;
		while (finder != _MyVector.end())
		{
			if (*check == *finder)
				throw DoubledNbException();
			finder++;
		}
		check++;
	}
}

void	PmergeMe::mergeAll(std::vector<int> &first, std::vector<int> &second)
{
	int jacob[11] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365};
	int i = 1;
	int size = first.size();

	_ites = second.begin();
	std::vector<int>::iterator temps = _ites;

	first.insert(first.begin(), *_ites);
	while (i < 11)
	{
		if (size >= jacob[i])
		{
			_itef = first.begin();
			temps = _ites;
			for (int x = 1; x != jacob[i]; x++)
				temps++;
			while (*_itef < *temps)
				_itef++;
			first.insert(_itef, *temps);
			for (int x = 1; x != (jacob[i] - jacob[i - 1]); x++)
			{
				temps--;
				_itef = first.begin();
				while (*_itef < *temps)
					_itef++;
				first.insert(_itef, *temps);
			}
		}
		else
			break ;
		i++;
	}
	temps = _ites;
	for (int x = 0; x != jacob[i - 1]; x++)
		temps++;
	while (temps != second.end())
	{
		_itef = first.begin();
		while (*_itef < *temps && _itef != first.end())
			_itef++;
		if (_itef != first.end())
			first.insert(_itef, *temps);
		else
			first.push_back(*temps);
		temps++;
	}
}

void	PmergeMe::sortFirst(std::vector<int> &first, std::vector<int> &second)
{
	std::vector<int>::iterator itfn = _itef;
	++itfn;

	std::vector<int>::iterator itsn = _ites;
	++itsn;

	while (itfn != first.end())
	{
		if (*_itef > *itfn)
		{
			int tempf = *_itef;
			*_itef = *itfn;
			*itfn = tempf;

			int temps = *_ites;
			*_ites = *itsn;
			*itsn = temps;

			_itef = first.begin();
			itfn = _itef;
			++itfn;

			_ites = second.begin();
			itsn = _ites;
			++itsn;
		}
		else
		{
			_itef++;
			itfn++;
			_ites++;
			itsn++;
		}
	}
}

void	PmergeMe::sortVector()
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int>::iterator ite = _MyVector.begin();

	while (ite !=  _MyVector.end())
	{
		std::vector<int>::iterator itn = ite;
		itn++;
		if (itn ==  _MyVector.end())
		{
			second.push_back(*ite);
			break ;
		}
		
		if (*ite < *itn)
		{
			second.push_back(*ite);
			first.push_back(*itn);
		}
		else
		{
			first.push_back(*ite);
			second.push_back(*itn);
		}
		std::advance(ite, 2);
	}

	_itef = first.begin();
	_ites = second.begin();

	_MyVector.clear();
	sortFirst(first, second);
	mergeAll(first, second);
	_MyVector.swap(first);
}

void	PmergeMe::mergeAllL(std::list<int> &first, std::list<int> &second)
{
	int jacob[11] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365};
	int i = 1;
	int size = first.size();

	_Lites = second.begin();
	std::list<int>::iterator temps = _Lites;

	first.insert(first.begin(), *_Lites);
	while (i < 11)
	{
		if (size >= jacob[i])
		{
			_Litef = first.begin();
			temps = _Lites;
			for (int x = 1; x != jacob[i]; x++)
				temps++;
			while (*_Litef < *temps)
				_Litef++;
			first.insert(_Litef, *temps);
			for (int x = 1; x != (jacob[i] - jacob[i - 1]); x++)
			{
				temps--;
				_Litef = first.begin();
				while (*_Litef < *temps)
					_Litef++;
				first.insert(_Litef, *temps);
			}
		}
		else
			break ;
		i++;
	}
	temps = _Lites;
	for (int x = 0; x != jacob[i - 1]; x++)
		temps++;
	while (temps != second.end())
	{
		_Litef = first.begin();
		while (*_Litef < *temps && _Litef != first.end())
			_Litef++;
		if (_Litef != first.end())
			first.insert(_Litef, *temps);
		else
			first.push_back(*temps);
		temps++;
	}
}

void	PmergeMe::sortFirstL(std::list<int> &first, std::list<int> &second)
{
	std::list<int>::iterator itfn = _Litef;
	++itfn;

	std::list<int>::iterator itsn = _Lites;
	++itsn;

	while (itfn != first.end())
	{
		if (*_Litef > *itfn)
		{
			int tempf = *_Litef;
			*_Litef = *itfn;
			*itfn = tempf;

			int temps = *_Lites;
			*_Lites = *itsn;
			*itsn = temps;

			_Litef = first.begin();
			itfn = _Litef;
			++itfn;

			_Lites = second.begin();
			itsn = _Lites;
			++itsn;
		}
		else
		{
			_Litef++;
			itfn++;
			_Lites++;
			itsn++;
		}
	}
}

void	PmergeMe::sortList()
{
	std::list<int> first;
	std::list<int> second;
	std::list<int>::iterator ite = _MyList.begin();

	while (ite !=  _MyList.end())
	{
		std::list<int>::iterator itn = ite;
		itn++;
		if (itn ==  _MyList.end())
		{
			second.push_back(*ite);
			break ;
		}
		
		if (*ite < *itn)
		{
			second.push_back(*ite);
			first.push_back(*itn);
		}
		else
		{
			first.push_back(*ite);
			second.push_back(*itn);
		}
		std::advance(ite, 2);
	}

	_Litef = first.begin();
	_Lites = second.begin();

	_MyList.clear();
	sortFirstL(first, second);
	mergeAllL(first, second);
	_MyList.swap(first);
}

void	PmergeMe::affVector()
{
	std::cout << WHITE_BOLD << "Vector : ";
	for (std::vector<int>::iterator  it = getBegin(); it != getEnd(); it++)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;

}

void	PmergeMe::affList()
{
	std::cout << WHITE_BOLD << "List : ";
	for (std::list<int>::iterator  it = getLBegin(); it != getLEnd(); it++)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;

}

std::vector<int>::iterator PmergeMe::getBegin()
{
	return (_MyVector.begin());
}

std::vector<int>::iterator PmergeMe::getEnd()
{
	return (_MyVector.end());
}

std::list<int>::iterator PmergeMe::getLBegin()
{
	return (_MyList.begin());
}

std::list<int>::iterator PmergeMe::getLEnd()
{
	return (_MyList.end());
}

const char* PmergeMe::DoubledNbException::what() const throw()
{
	return "Duplicate numbers";
}

const char* PmergeMe::ErrorInParsingException::what() const throw()
{
	return "Error.";
}

std::ostream	&	operator<<( std::ostream & o, PmergeMe &rhs)
{
	o << GREEN << "After: ";
	for (std::vector<int>::iterator  it = rhs.getBegin(); it != rhs.getEnd(); it++)
		o << *it << " ";
	std::cout << RESET;
	return o;
}









