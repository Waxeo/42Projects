#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    public:

        Dog( void );
        Dog( std::string name );
		Dog( const Dog &src );
        virtual ~Dog( void );
        
		Dog	&operator=( Dog const &src );

		virtual void makeSound( void ) const;

		virtual Brain*	getBrain() const;
		virtual void	setBrain(std::string idea);
    
    private:

        Brain   *_Brain;
};

#endif