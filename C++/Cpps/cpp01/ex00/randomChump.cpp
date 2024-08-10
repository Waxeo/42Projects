#include "Zombie.Class.hpp"

void	randomChump( std::string name )
{
	Zombie Random = Zombie(name);
	Random.announce();

	return ;
}
