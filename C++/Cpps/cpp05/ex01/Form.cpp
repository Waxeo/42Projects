#include "Form.hpp"

Form::Form( void ) : _Name("Random Form"), _Signed(false), _SignGrade(100), _ExecGrade(50)
{
	return ;
}

Form::Form( std::string name, int signgrade, int execgrade ) : _Name(name), _Signed(false), _SignGrade(signgrade), _ExecGrade(execgrade)
{
	if (signgrade > 150 || execgrade > 150)
		throw GradeTooLowException();
	if (signgrade < 1 || execgrade < 1)
		throw GradeTooHighException();
	return ;
}

Form::Form( Form const &src ) : _Name(src.getName()), _Signed(src.getSigned()), _SignGrade(src.getSignGrade()), _ExecGrade(src.getExecGrade())
{
	return ;
}

Form::~Form( void )
{
	return ;
}

Form	&Form::operator=( Form const &rhs )
{
	if (this != &rhs)
		this->_Signed = rhs.getSigned();

	return *this;
}

std::string		Form::getName() const 
{
	return this->_Name;
}

bool			Form::getSigned() const
{
	return this->_Signed;
}

int			Form::getSignGrade() const
{
	return this->_SignGrade;
}

int			Form::getExecGrade() const
{
	return this->_ExecGrade;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_Signed == false)
	{
		if (bureaucrat.getGrade() <= this->_SignGrade)
		{
			bureaucrat.signForm(1, this->_Name);
			this->_Signed = true;

			return ;
		}
		else
		{
			bureaucrat.signForm(2, this->_Name);
			return ;
		}
	}

	bureaucrat.signForm(3, this->_Name);
	return ;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream	&operator<<( std::ostream & o, Form const &rhs)
{
	o << "Form : \"" << rhs.getName() << "\"";
	if (rhs.getSigned() == false)
		std::cout << " is not signed." << std::endl;
	else
		std::cout << " is signed." << std::endl;

	std::cout << "Grade required to sign it : " << rhs.getSignGrade() << ". Grade required to execute it : " << rhs.getExecGrade() << "." << std::endl;

	return o;
}