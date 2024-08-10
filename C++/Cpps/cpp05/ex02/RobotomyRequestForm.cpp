#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Random RobotomyRequestForm", 72, 45), _Target("home")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("Random RobotomyRequestForm", 72, 45), _Target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src )
{
	*this = src;

	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs )
{
	if (this != &rhs)
		this->_Target = rhs._Target;

	return *this;
}

void RobotomyRequestForm::exec( void ) const
{
	std::srand(std::time(NULL));
	int x = std::rand();

	if (x % 2)
		std::cout << "ZBRREEEEHHHHHH "<< _Target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;

	return ;
}