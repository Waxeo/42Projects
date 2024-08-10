#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Random PresidentialPardonForm", 25, 5), _Target("home")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("Random PresidentialPardonForm", 25, 5), _Target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &src )
{
	*this = src;

	return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs )
{
	if (this != &rhs)
		this->_Target = rhs._Target;

	return *this;
}

void PresidentialPardonForm::exec( void ) const
{
	std::cout << _Target << " has been pardoned by Zaphod Beeblebrox." << std::endl;

	return ;
}
