#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern( void )
{
	return ;
}

Intern::Intern( Intern const &src )
{
	(void)src;
	return ;
}

Intern::~Intern( void )
{
	return ;
}

Intern	&Intern::operator=( Intern const &rhs )
{
	(void)rhs;
	return *this;
}

static AForm*	createPresidential(const std::string& target)
{
	std::cout << "Intern creates presidential pardon form" << std::endl;
	return new PresidentialPardonForm(target);
}

static AForm*	createRobotomy(const std::string& target)
{
	std::cout << "Intern creates robotomy request form" << std::endl;

	return new RobotomyRequestForm(target);
}

static AForm*	createShrubbery(const std::string& target)
{
	std::cout << "Intern creates shurbbery creation form" << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	AForm *ret = NULL;

 	static  FormList formList[3] = {
        {"presidential request", createPresidential},
        {"robotomy request", createRobotomy},
        {"shrubbery request", createShrubbery}
    };

	for (int i = 0; i < 3; i++)
	{
		if (form == formList[i].name)
		{
			ret = formList[i].create(target);
   			return ret;
		}
	}

	throw NotExistingFormException();
}

const char* Intern::NotExistingFormException::what() const throw()
{
	return "No form match this name.";
}
