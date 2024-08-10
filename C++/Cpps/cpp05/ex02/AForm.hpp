#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"

class AForm
{
	public:

		AForm( void );
		AForm( std::string name, int signgrade, int execgrade );
		AForm( AForm const &src );
		~AForm( void );

		AForm	&	operator=( AForm const &rhs );

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

		class NotSignedException : public std::exception
		{
    		public:
       			virtual const char* what() const throw();
		};

		int	execute(Bureaucrat const & executor) const;

	protected:
		virtual void	exec( void ) const = 0;

	private:

		const std::string _Name;
		bool	_Signed;
		const int		_SignGrade;
		const int		_ExecGrade;
};

std::ostream	&	operator<<( std::ostream & o, AForm const &rhs);


#endif