#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[5;96m"

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(std::string Type);
        ~Weapon();
		const std::string	&getType( void );
		void	setType(std::string type);
};

#endif