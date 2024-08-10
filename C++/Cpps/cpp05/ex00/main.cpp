#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		std::cout << GREEN << "//////////TEST1/////////" << RESET << std::endl;
		Bureaucrat test1("Zo", 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		std::cout << GREEN << "//////////TEST1.V2/////////" << RESET << std::endl;
		Bureaucrat test2("Zo", 151);
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		std::cout << GREEN << "//////////TEST2/////////" << RESET << std::endl;
		
		Bureaucrat test1;

		std::cout << test1;

		std::cout << "+2" << std::endl;
		test1.TryIncrement();
		test1.TryIncrement();
		std::cout << test1;

		std::cout << "-1" << std::endl;
		test1.TryDecrement();
		std::cout << test1;
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		std::cout << GREEN << "//////////TEST3/////////" << RESET << std::endl;
		
		Bureaucrat test1("Zo", 1);
		std::cout << test1;

		test1.TryIncrement();
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		std::cout << GREEN << "//////////TEST4/////////" << RESET << std::endl;

		Bureaucrat test1("Zo", 150);
		std::cout << test1;

		test1.TryDecrement();
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	return 0;
}