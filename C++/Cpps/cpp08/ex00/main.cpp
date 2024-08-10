#include "easyfind.hpp"

int main()
{
	std::cout << GREEN << "Test with occurence from vector" << RESET << std::endl;
	try
	{
		std::vector<int> test;

		for (size_t i = 0; i < 5; i++)
			test.push_back(i + 42);

		easyfind(test, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << GREEN << "Test with no occurence from vector" << RESET << std::endl;
	try
	{
		std::vector<int> test;

		for (size_t i = 0; i < 5; i++)
			test.push_back(i + 42);

		easyfind(test, 12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << GREEN << "Test with occurence from list" << RESET << std::endl;

	try
	{
		std::list<int> test2;

		for (size_t i = 0; i < 5; i++)
			test2.push_back(i + 2);

		easyfind(test2, 6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << GREEN << "Test with no occurence from list" << RESET << std::endl;

	try
	{
		std::list<int> test2;

		for (size_t i = 0; i < 5; i++)
			test2.push_back(i + 2);

		easyfind(test2, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}