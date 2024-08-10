#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Form
{
	public:

		Form( void );
		Form( std::string name, int signgrade, int execgrade );
		Form( Form const &src );
		~Form( void );

		Form	&	operator=( Form const &rhs );

		std::string		getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void	beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
    		public:
       			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
    		public:
       			virtual const char* what() const throw();
		};

	private:

		const std::string _Name;
		bool	_Signed;
		const int		_SignGrade;
		const int		_ExecGrade;
};

std::ostream	&	operator<<( std::ostream & o, Form const &rhs);


#endif