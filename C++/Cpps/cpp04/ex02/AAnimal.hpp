#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include "Brain.hpp"
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

class AAnimal
{
	public:

		AAnimal( void );
		AAnimal( std::string name );
		AAnimal( const AAnimal &src );
		virtual ~AAnimal( void );

		AAnimal	&operator=( AAnimal const &src );

		virtual void makeSound( void ) const = 0;

		std::string getType() const;

		virtual Brain*	getBrain() const;
		virtual void	setBrain(std::string idea);
		
	protected:

		std::string	_Type;

};

/* From now on, all your classes must be designed
in the Orthodox Canonical Form, unless explicitely
stated otherwise. Then, they will implement the four
required member functions below:

• Default constructor

• Copy constructor

• Copy assignment operator 

• Destructor */


#endif