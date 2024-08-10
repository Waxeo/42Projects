#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

#include "ClapTrap.Class.hpp"

class FragTrap : virtual public ClapTrap
{
    public:

        FragTrap( void );
        FragTrap( std::string name );
        FragTrap( FragTrap &src );
        ~FragTrap( void );

        // std::string getName( void );
        // int	        getHitPoints( void );
        // int		    getEnergyPoints( void );
		// int         getDamage( void );

	    void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif