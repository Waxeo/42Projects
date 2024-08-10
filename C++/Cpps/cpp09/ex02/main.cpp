#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	try
	{
		PmergeMe sort(ac, av);
	
		const std::clock_t c_start_vector = std::clock();
		sort.sortVector();
		const std::clock_t c_end_vector = std::clock();

		const std::clock_t c_start_list = std::clock();
		sort.sortList();
		const std::clock_t c_end_list = std::clock();
		
		std::cout << sort << std::endl << std::endl;

		std::cout  << CYAN << "Time to process a range of " << (ac - 1) << " elements with std::vector : " << (c_end_vector - c_start_vector) << " us" << std::endl;
		std::cout << "Time to process a range of " << (ac - 1) << " elements with std::list : " << (c_end_list - c_start_list) << " us" << RESET << std::endl;

		// sort.affVector();
		// sort.affList();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	
	return 0;
}