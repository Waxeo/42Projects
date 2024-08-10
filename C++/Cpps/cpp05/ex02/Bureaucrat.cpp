#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat( void ) : _Name("Random Bureaucrat"), _Grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _Name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	else
		this->_Grade = grade;
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) : _Name(src._Name), _Grade(src._Grade)
{
	return ;
}

Bureaucrat::~Bureaucrat( void )
{
	return ;
}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &rhs )
{
	if (this != &rhs)
		this->_Grade = rhs.getGrade();

	return *this;
}

std::string		Bureaucrat::getName() const 
{
	return this->_Name;
}

int		Bureaucrat::getGrade() const
{
	return this->_Grade;
}

void Bureaucrat::TryIncrement( void )
{
	if (this->_Grade - 1 < 1)
		throw GradeTooHighException();
	this->_Grade -= 1;
	return ;
}

void Bureaucrat::TryDecrement( void )
{
	if (this->_Grade + 1 > 150)
		throw GradeTooLowException();
	this->_Grade += 1;
	return ;
}

void	Bureaucrat::signForm(int message, std::string name) const
{
	switch (message)
	{
		case 1:
			std::cout << this->_Name << " signed " << name << std::endl;
			break ;

		case 2:
			std::cout << this->_Name << " couldn't sign " << name << " because his grade is to low." << std::endl;
			break ;


		case 3:
			std::cout << this->_Name << " couldn't sign " << name << " because this form is already signed." << std::endl;
			break ;

		default:
			std::cout << "Signing Problem" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	int test = form.execute(*this);

	if (test == -1)
	{
		std::cout << this->_Name << " failed to execute the form : Form not signed" << std::endl;
		return ;
	}
	if (test == -2)
	{
		std::cout << this->_Name << " failed to execute the form : Grade too low" << std::endl;
		return ;
	}

	std::cout << this->_Name << " executed " << form.getName() <<  std::endl;

	return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream	&operator<<( std::ostream & o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;

	return o;
}
