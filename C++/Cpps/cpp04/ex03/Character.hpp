#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:

		Character(std::string name);
		Character(Character const &src);
		~Character();

		Character	&operator=(Character const &rhs);

		virtual std::string const & getName() const;

		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		void    displayInventory(void) const;

	
	private:

		AMateria *_inventory[4];
		std::string _name;
		int _idx;
};

#endif