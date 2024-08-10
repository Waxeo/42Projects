#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Weapon.Class.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[5;96m"

class HumanB
{
	private:
		std::string _name;
		Weapon      *_weapon;
	public:
		HumanB(std::string Name);
		~HumanB();
		void    attack( void );
		void    setWeapon(Weapon &weapon);
};

#endif