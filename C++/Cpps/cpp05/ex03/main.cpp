#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		std::cout << GREEN << "//////////TEST1/////////" << RESET << std::endl;

		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("presidential request", "Bender");

		std::cout << rrf->getName() << std::endl;

		delete rrf;
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << GREEN << "//////////TEST2/////////" << RESET << std::endl;

		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		std::cout << rrf->getName() << std::endl;

		delete rrf;
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << GREEN << "//////////TEST3/////////" << RESET << std::endl;

		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("shrubbery request", "Bender");

		std::cout << rrf->getName() << std::endl;

		delete rrf;
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << GREEN << "//////////TEST4/////////" << RESET << std::endl;

		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("random request", "Bender");

		std::cout << rrf->getName() << std::endl;

		

	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	
	return 0;
}