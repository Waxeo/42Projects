#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &src);
		virtual ~Cure();

		Cure	&operator=(Cure const &rhs);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif