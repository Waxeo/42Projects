#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	public:

		MateriaSource();
		MateriaSource(const MateriaSource &src);
		~MateriaSource();

		MateriaSource &operator=(const MateriaSource &rhs);

		virtual void learnMateria(AMateria*f);
		virtual AMateria* createMateria(std::string const & type);

		void    displayModels(void);


	private:
		AMateria *_learned[4];
		int		_index;
};

#endif