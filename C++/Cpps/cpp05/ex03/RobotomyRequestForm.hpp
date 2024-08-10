#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:

		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const &src );
		virtual ~RobotomyRequestForm( void );

		RobotomyRequestForm	&	operator=( RobotomyRequestForm const &rhs );

		void exec( void ) const;

	private:

		RobotomyRequestForm( void );

		std::string _Target;
		
};

#endif