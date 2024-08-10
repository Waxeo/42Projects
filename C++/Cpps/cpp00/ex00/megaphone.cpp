#include <iostream>

void	capitalizer(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			av[i][j] = std::toupper(av[i][j]);
	}
}

int	main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	capitalizer(ac, av);
	while (++i < ac)
		std::cout << av[i];
	std::cout << "\n";
	return (0);
}