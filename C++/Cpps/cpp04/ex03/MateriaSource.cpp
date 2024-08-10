#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _learned(), _index(0)
{
    for (int i = 0; i < 4; ++i)
		_learned[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &src) : _index(src._index)
{
    for (int i = 0; i < 4; ++i)
		_learned[i] = NULL;
	*this = src;

	return ;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _index; i++)
	{
		if (_learned[i] != NULL)
			delete _learned[i];
	}
	return ;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i <= _index; ++i)
		{
			if (_learned[i])
            	delete _learned[i];
		}
        _index = rhs._index;

        for (int i = 0; i < 4; i++)
    	{
			if (rhs._learned[i] != NULL)
				this->_learned[i] = rhs._learned[i]->clone();
    	}
    }

    return *this;
}

void 	MateriaSource::learnMateria(AMateria* f)
{
	if (_index < 4 && f)
	{
		_learned[_index] = f;
		_index++;
	}
	else
	{
		if (f)
			delete f;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _index; ++i)
    {
		if (_learned[i])
		{
        	if (_learned[i]->getType() == type)
           		return _learned[i]->clone();
		}
    }

    return NULL;
}

void    MateriaSource::displayModels(void)
{
    std::cout << YELLOW << "MateriaSource has learned the types:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << i << ". ";
        if (this->_learned[i] == NULL)
            std::cout << "Empty slot.";
        else
            std::cout << this->_learned[i]->getType() << " materia.";
        std::cout << std::endl;
    }
    std::cout << std::endl << RESET;
    return ;
}