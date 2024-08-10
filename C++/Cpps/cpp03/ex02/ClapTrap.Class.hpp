#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[5;96m"

class ClapTrap
{
	public:

		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap &src );
		~ClapTrap( void );

		ClapTrap	&operator=( ClapTrap const &src );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName( void );
		int getDamage( void );

	protected:

		std::string	_Name;
		int	_HitPoints;
		int	_EnergyPoints;
		int	_AttackDamage;
};

/*From now on, all your classes must be designed
 in the Orthodox Canonical Form, unless explicitely
  stated otherwise. Then, they will implement the four
   required member functions below:

• Default constructor

• Copy constructor

• Copy assignment operator 

• Destructor*/


#endif