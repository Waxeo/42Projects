#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		/*File Management*/
		std::string ifstring = av[1];//gestion file d'input
		std::ifstream ifs;
		ifs.open(ifstring.c_str());
		if (!ifs.is_open())
		{
			std::cout << "Failed to open the file" << std::endl;
			return (-1);
		}

		std::string ofstring = ifstring + ".replace";//gestion .replace file
		std::ofstream ofs;
		ofs.open(ofstring.c_str());
		if (!ofs.is_open())
		{
			std::cout << "Failed to open the .replace file" << std::endl;
			return (-1);
		}

		/*Copy, Replace n Add*/
		std::string str = av[2];
		if (str.empty())
		{
			std::cout << "Empty ToFind string" << std::endl;
			return (-1);
		}
		std::string nstr = av[3];
		std::string	copy;//copy from file to .replace
		int			i;
		while (std::getline(ifs, copy))
		{
			i = 0;
			while (1)
			{
				std::size_t found = copy.find(av[2], i);
				i = (int)found + nstr.size();
				if (found == std::string::npos)
					break ;
				copy.erase(found, str.size());
				copy.insert(found, nstr);
			}
			ofs << copy << std::endl;
		}
		ifs.close();

		return (0);
	}
	std::cerr << "Wrong Input" << std::endl;
	return (-1);
}
