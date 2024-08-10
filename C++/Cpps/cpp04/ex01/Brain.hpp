#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

class Brain
{
    public:

        Brain( void );
		Brain( Brain &src );
        virtual ~Brain( void );
        
		Brain	&operator=( Brain const &src );

		void	setIdeas(std::string idea);
		void	getIdeas();
	
	private:
	
		std::string _Ideas[100];
};

#endif