#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

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

class HumanA
{
    private:
        std::string _name;
        Weapon      &_weapon;
    public:
        HumanA(std::string Name, Weapon &Weapon);
        ~HumanA();
        void    attack( void );
};

#endif