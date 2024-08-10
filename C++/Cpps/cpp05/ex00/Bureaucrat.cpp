#include "Bureaucrat.hpp"

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
