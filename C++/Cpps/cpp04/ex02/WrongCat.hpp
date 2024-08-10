#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:

        WrongCat( void );
        WrongCat( std::string name );
        virtual ~WrongCat( void );
	    
		WrongCat	&operator=( WrongCat const &src );

		void makeSound( void ) const;
};

#endif