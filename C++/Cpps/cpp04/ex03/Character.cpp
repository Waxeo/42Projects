#include "Character.hpp"

Character::Character(std::string name) :  _name(name), _idx(0)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	return ;
}

Character::Character(Character const &src) : _idx(src._idx)
{
    for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	*this = src;

	return ;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}	
	return ;
}

Character	&Character::operator=(Character const &rhs)
{
	if (this != &rhs)
    {
        for (int i = 0; i <= _idx; ++i)
		{
			if (_inventory[i])
            	delete _inventory[i];
		}
        _idx = rhs._idx;

        for (int i = 0; i < 4; i++)
    	{
			if (rhs._inventory[i] != NULL)
				this->_inventory[i] = rhs._inventory[i]->clone();
    	}
    }

    return *this;
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "No empty slot for a new Materia" << std::endl;

	return ;
}

void Character::unequip(int idx)
{
	if ((idx > 0 && idx < 4) && _inventory[idx])
	{
		_inventory[idx] = NULL;
		_idx--;
	}

}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (_inventory[idx] == NULL)
		std::cout << "This slot contains no Materia" << std::endl;
	else
		_inventory[idx]->use(target);

	return ;
}

void    Character::displayInventory(void) const
{
    std::cout << this->_name << "'s inventory :" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << i << ". ";
        if (this->_inventory[i] == NULL)
            std::cout << "Empty slot.";
        else
            std::cout << this->_inventory[i]->getType() << " materia.";
        std::cout << std::endl;
    }
    return ;
}