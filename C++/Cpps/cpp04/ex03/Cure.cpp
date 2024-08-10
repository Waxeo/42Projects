#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	return ;
}
		
Cure::Cure(Cure const &src) : AMateria("cure")
{
	this->_type = src._type;
	return ;
}

Cure::~Cure()
{
	return ;
}

Cure	&Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	
	return *this;
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}