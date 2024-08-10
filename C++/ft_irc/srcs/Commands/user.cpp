#include "Server.hpp"

void	Server::user(Client &client){
		
	std::string user;

	for (size_t i = 1; i < client.getBuf().size(); i++){
		user += client.getBuf()[i];
		if (i < client.getBuf().size() - 1)
			user += " ";
	}

	if (client.getNickName().empty() || client.getPass().empty()){
		std::cerr << RED << ERR_NOTREGISTERED(_name) << RESET << std::endl;
		std::cerr << RED << "Enter PASS, NICK, USER in this order" << RESET << std::endl;
		return;
	}
	else if (client.getBuf().size() == 1){
		std::cerr << RED << ERR_NEEDMOREPARAMS(_name, client.getBuf()[0]) << RESET << std::endl;
		return;
	}
	else if (client.getBuf().size() > 2){
		std::cerr << RED << ERR_ERRONEUSUSER(_name, user) << RESET << std::endl;
		return;
	}
	else if (client.getUserName().empty() == false){
		std::cerr << RED << ERR_ALREADYREGISTRED(_name) << RESET << std::endl;
		return;
	}
	else
	{
		for (size_t i = 0; i < client.getBuf()[1].size(); i++)
		{
			if (!isalnum(client.getBuf()[1][i]))
			{
				std::cerr << RED << ERR_ERRONEUSUSER(_name, user) << RESET << std::endl;
				return ;
			}
		}
		client.setUserName(client.getBuf()[1]);
		std::cout << GREEN << "Client " << client.getId() << " connected" << RESET << std::endl;
		client.setRpl(RPL_WELCOME(user_id(user, client.getNickName()), client.getNickName()));
		send(client.getSocket(), client.getRpl().c_str(), client.getRpl().size(), 0);
		return ;
	}
}

void	Server::userIrssi(Client &client, int i){
	std::string user;
	for (size_t j = i + 1; client.getBuf()[j] != "localhost" && j < client.getBuf().size(); j++){
		user += client.getBuf()[j];
		if (client.getBuf().size() > j){
			if (client.getBuf()[j + 1] != "localhost")
				user += " ";
		}
	}
	client.setUserName(user);
}