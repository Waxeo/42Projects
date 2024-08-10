#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:

		ShrubberyCreationForm( std::string target);
		ShrubberyCreationForm( ShrubberyCreationForm const &src );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm	&	operator=( ShrubberyCreationForm const &rhs );

		void exec( void ) const;

	private:

		ShrubberyCreationForm( void );
		
		std::string _Target;
		static const std::string _shrubbery1;
	
};

#endif