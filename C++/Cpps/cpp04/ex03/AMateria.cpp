#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria( void ) : _type("Random")
{
	return ;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	return ;
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
}

AMateria::~AMateria()
{
	return ;
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "use random Materia against " << target.getName() << std::endl;
	return ;
}