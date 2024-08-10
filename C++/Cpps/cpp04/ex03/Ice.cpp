#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	return ;
}
		
Ice::Ice(Ice const &src) : AMateria("ice")
{
	this->_type = src._type;
	return ;
}

Ice::~Ice()
{
	return ;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	
	return *this;
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}