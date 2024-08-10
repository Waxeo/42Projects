#include "Harl.Class.hpp"

Harl::Harl( void )
{
	std::cout << "Harl enters in his favorite fast-food" << std::endl;
    return ;
}

Harl::~Harl( void )
{
	std::cout << "Harl gets out smashing the exit door" << std::endl;

    return ;
}

void    Harl::complain( std::string level )
{
	void		(Harl::*ptr_complain[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*ptr_complain[i])();
			return ;
		}
		i++;
	}
	
	std::cout << "This level does not exist" << std::endl;
    return ;
}

void	Harl::_debug( void )
{
	std::cout << GREEN << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. \
I really do !" << RESET << std::endl;

	return ;
}
void	Harl::_info( void )
{
	std::cout << BLUE << "I cannot believe adding extra bacon \
costs more money. You didn't put enough bacon in my burger ! \
If you did, I wouldn't be asking for more !" << RESET << std::endl;

	return ;
}

void	Harl::_warning( void )
{
	std::cout << YELLOW << "I think I deserve to have some \
extra bacon for free. I've been comingfor years whereas \
you started working here since last month." << RESET << std::endl;
	return ;
}

void	Harl::_error( void )
{
	std::cout << RED << "This is unacceptable ! I want to speak \
to the manager now." << RESET << std::endl;
	
	return ;
}