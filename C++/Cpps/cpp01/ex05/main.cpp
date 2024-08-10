#include "Harl.Class.hpp"

int	main()
{
	Harl Harl;

	Harl.complain("DEBUG");
	std::cout << std::endl;
	Harl.complain("INFO");
	std::cout << std::endl;
	Harl.complain("WARNING");
	std::cout << std::endl;
	Harl.complain("ERROR");
	std::cout << std::endl;
	Harl.complain("CRYING");
	std::cout << std::endl;


	return (0);
}