#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

#include "ClapTrap.Class.hpp"

class FragTrap : public ClapTrap
{
    public:

        FragTrap( std::string name );
        FragTrap( FragTrap &src );
        ~FragTrap( void );

	    void attack(const std::string& target);
        void highFivesGuys(void);

    private :
        FragTrap( void );
};

#endif