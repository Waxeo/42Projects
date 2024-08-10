#include "Server.hpp"
#include "utils.hpp"

void	Server::pass(Client &client){
	
	if (client.getBuf().size() == 1) {
		std::cerr << RED << ERR_NEEDMOREPARAMS(_name, client.getBuf()[0]) << RESET << std::endl;
		return;
	}
	else if (client.getBuf().size() > 2) {
		std::cerr << RED << ERR_PASSWDMISMATCH(_name) << RESET << std::endl;
		return ;
	}
	else if (client.getPass().empty())
	{
		if (client.getBuf()[1].compare(_password))
		{
			std::cerr << RED << ERR_PASSWDMISMATCH(_name) << RESET << std::endl;
			client.setDeco();
			deleteClient(client);
			return ;
		}
		else {
			client.setPass(client.getBuf()[1]);
			return ;
		}
	}
	else
		std::cerr<< RED << ERR_ALREADYREGISTRED(_name) << RESET << std::endl;
}

bool	Server::passIrssi(Client &client, int i){
	if (client.getBuf().size() >= ((size_t)i + 2)){
		if (client.getBuf()[i + 2] != "NICK"){
			std::cerr << RED << ERR_PASSWDMISMATCH(_name) << RESET << std::endl;
			return false;
		}
		else if (client.getBuf()[i + 1] != _password){
			std::cerr << RED << ERR_PASSWDMISMATCH(_name) << RESET << std::endl;
			return false;
		}
		else
			client.setPass(client.getBuf()[i + 1]);
	}
	return true;	
}