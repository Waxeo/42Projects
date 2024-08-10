#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		std::cout << GREEN << "//////////TEST1/////////" << RESET << std::endl;

		Bureaucrat test1("Peter", 75);
		Form	form1;

		std::cout << test1;

		form1.beSigned(test1);

		std::cout << std::endl;
		std::cout << form1;
		std::cout << std::endl;

		form1.beSigned(test1);

	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		std::cout << GREEN << "//////////TEST2/////////" << RESET << std::endl;

		Bureaucrat test1("Peter", 143);
		Form	form1;

		std::cout << test1;

		form1.beSigned(test1);

		std::cout << std::endl;
		std::cout << form1;
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		std::cout << GREEN << "//////////TEST3/////////" << RESET << std::endl;

		Form	form1("adm", 151, 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

		try
	{
		std::cout << GREEN << "//////////TEST3.V2/////////" << RESET << std::endl;

		Form	form1("adm", 100, 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}



	return 0;
}