#ifndef DIAMONDTRAP_CLASS_HPP
# define DIAMONDTRAP_CLASS_HPP

#include "ClapTrap.Class.hpp"
#include "ScavTrap.Class.hpp"
#include "FragTrap.Class.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
    public:

        DiamondTrap( void );
        DiamondTrap( std::string name );
        DiamondTrap( DiamondTrap &src );
        ~DiamondTrap( void );
        
	    void attack(const std::string& target);

        std::string getName( void );
        int	        getHitPoints( void );
        int		    getEnergyPoints( void );
		int         getDamage( void );

        void whoAmI( void );

    private :

		std::string _Name;
        int	_HitPoints;
		int	_EnergyPoints;
		int	_AttackDamage;
};

#endif