#include "AForm.hpp"

AForm::AForm( void ) : _Name("Random AForm"), _Signed(false), _SignGrade(100), _ExecGrade(50)
{
	return ;
}

AForm::AForm( std::string name, int signgrade, int execgrade ) : _Name(name), _Signed(false), _SignGrade(signgrade), _ExecGrade(execgrade)
{
	if (signgrade > 150 || execgrade > 150)
		throw GradeTooLowException();
	if (signgrade < 1 || execgrade < 1)
		throw GradeTooHighException();
	return ;
}

AForm::AForm( AForm const &src ) : _Name(src.getName()), _Signed(src.getSigned()), _SignGrade(src.getSignGrade()), _ExecGrade(src.getExecGrade())
{
	return ;
}

AForm::~AForm( void )
{
	return ;
}

AForm	&AForm::operator=( AForm const &rhs )
{
	if (this != &rhs)
		this->_Signed = rhs.getSigned();

	return *this;
}

std::string		AForm::getName() const 
{
	return this->_Name;
}

bool			AForm::getSigned() const
{
	return this->_Signed;
}

int			AForm::getSignGrade() const
{
	return this->_SignGrade;
}

int			AForm::getExecGrade() const
{
	return this->_ExecGrade;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
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

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form not signed";
}

int	AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_Signed)
	{
		throw NotSignedException();
		return -1;
	}

	if (executor.getGrade() > this->_ExecGrade)
	{
		throw GradeTooLowException();
		return -2;
	}

	this->exec();
	return 0;
}


std::ostream	&operator<<( std::ostream & o, AForm const &rhs)
{
	o << "AForm : \"" << rhs.getName() << "\"";
	if (rhs.getSigned() == false)
		std::cout << " is not signed." << std::endl;
	else
		std::cout << " is signed." << std::endl;

	std::cout << "Grade required to sign it : " << rhs.getSignGrade() << ". Grade required to execute it : " << rhs.getExecGrade() << "." << std::endl;

	return o;
}