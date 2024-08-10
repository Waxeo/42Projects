#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


int	main()
{
	try
	{
		std::cout << GREEN << "//////////TEST1/////////" << RESET << std::endl;

		Bureaucrat test1("Peter", 1);
		RobotomyRequestForm form1("suu");

		form1.beSigned(test1);

		test1.executeForm(form1);

	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << GREEN << "//////////TEST2/////////" << RESET << std::endl;

		Bureaucrat test1("Peter", 1);
		PresidentialPardonForm form1("suu");

		form1.beSigned(test1);

		test1.executeForm(form1);

	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << GREEN << "//////////TEST3/////////" << RESET << std::endl;

		Bureaucrat test1("Peter", 1);
		ShrubberyCreationForm form1("suu");

		form1.beSigned(test1);

		test1.executeForm(form1);

	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << GREEN << "//////////TEST4/////////" << RESET << std::endl;

		Bureaucrat test1("Peter", 140);
		ShrubberyCreationForm form1("suu");

		form1.beSigned(test1);

		test1.executeForm(form1);

	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << GREEN << "//////////TEST5/////////" << RESET << std::endl;

		Bureaucrat test1("Peter", 1);
		ShrubberyCreationForm form1("suu");

		test1.executeForm(form1);

	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	return 0;
}