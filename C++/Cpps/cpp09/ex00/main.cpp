#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        BitcoinExchange Init;

        Init.extractAndExec(av[1]);

        return 0;
    }


    std::cout << "Error : Could not open file" << std::endl;

    return -1;
}