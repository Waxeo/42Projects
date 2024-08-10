#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

#include "ClapTrap.Class.hpp"

class ScavTrap : virtual public ClapTrap 
{
    public:

        ScavTrap( void );
        ScavTrap( std::string name );
		ScavTrap( ScavTrap &src );
        ~ScavTrap( void );
        
	    void attack(const std::string& target);
        void guardGate( void );
};

#endif