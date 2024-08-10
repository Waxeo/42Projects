#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string test = av[1];

		ScalarConverter::convert(test);
	}

	return (0);
}