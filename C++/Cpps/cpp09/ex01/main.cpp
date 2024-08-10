#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
           RPN rpn(av[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}