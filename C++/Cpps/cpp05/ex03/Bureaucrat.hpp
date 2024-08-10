#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[5;96m"

class AForm;

class Bureaucrat
{
	public:

		Bureaucrat( void );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const &src );
		~Bureaucrat( void );

		Bureaucrat	&	operator=( Bureaucrat const &rhs );

		std::string		getName() const ;
		int			getGrade() const;

		void TryIncrement( void );
		void TryDecrement( void );

		void	signForm(int message, std::string name) const;

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

		void	executeForm(AForm const & form);

	private:

		const std::string _Name;
		int		_Grade;

};

std::ostream	&	operator<<( std::ostream & o, Bureaucrat const &rhs);

#endif

/* From now on, all your classes must be designed
in the Orthodox Canonical Form, unless explicitely
stated otherwise. Then, they will implement the four
required member functions below:

• Default constructor

• Copy constructor

• Copy assignment operator 

• Destructor */