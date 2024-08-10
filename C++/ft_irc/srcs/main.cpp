
#include "Server.hpp"


int main(int ac, char **av) {

    if (ac == 3){
        try {
            Server server(std::atoi(av[1]), av[2]);
            server.process();
        }
        catch (std::exception &e) {
            
        }
    }
    else
        std::cerr << RED << "Wrong number of arguments" << RESET << std::endl;
}
