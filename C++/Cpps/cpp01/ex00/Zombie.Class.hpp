#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

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

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(std::string Zname);
        ~Zombie();
        void    announce( void );
        Zombie* newZombie( std::string name );
        void randomChump( std::string name );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif