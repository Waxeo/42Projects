#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

# define BLACK    "\e[30m"
# define RED    "\e[31m"
# define GREEN    "\e[32m"
# define YELLOW    "\e[33m"
# define BLUE    "\e[34m"
# define PURPLE    "\e[35m"
# define CYAN    "\e[36m"
# define WHITE    "\e[37m"
# define RESET  "\e[0m"

class ICharacter;

class AMateria
{
	protected:

		std::string _type;

	public:
	
		AMateria( void );
		AMateria(std::string const & type);
		AMateria(AMateria const &src);
		virtual ~AMateria();
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif