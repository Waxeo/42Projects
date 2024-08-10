#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:

		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const &src );
		~PresidentialPardonForm( void );

		PresidentialPardonForm	&	operator=( PresidentialPardonForm const &rhs );

		void exec( void ) const;

	private:

		PresidentialPardonForm( void );

		std::string _Target;
};

#endif