#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:

		Cat( void );
		Cat( std::string name );
		Cat( const Cat &src );
		virtual ~Cat( void );
		
		Cat	&operator=( Cat const &src );

		virtual void makeSound( void ) const;

		virtual Brain*	getBrain() const;
		virtual void	setBrain(std::string idea);

	private:
	
		Brain   *_Brain;
};

#endif