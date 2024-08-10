#include "Server.hpp"

void	Server::nick(Client &client){

	if (client.getBuf().size() == 1) {
		std::cerr << RED << ERR_NEEDMOREPARAMS(_name, client.getBuf()[0]) << RESET << std::endl;
		return ;
	}
	std::string nickname;

	for (size_t i = 1; i < client.getBuf().size(); i++){
		nickname += client.getBuf()[i];
		if (i < client.getBuf().size() - 1)
			nickname += " ";
	}
	
	if (client.getBuf().size() > 2){
		std::cerr << RED << ERR_ERRONEUSNICKNAME(_name, nickname) << RESET << std::endl;
	}
	else if (!client.getPass().empty())
	{
		for (size_t i = 0; i < client.getBuf()[1].size(); i++)
		{
			if (!isalnum(client.getBuf()[1][i]))
			{
				std::cerr << RED << ERR_ERRONEUSNICKNAME(_name, nickname) << RESET << std::endl;
				client.getBuf().clear();
				return ;
			}
		}
		for (std::map<int, Client>::iterator ite = clientsManage.begin(); ite != clientsManage.end(); ite++)
		{
			if (nickname.size() > 9)
				nickname = nickname.substr(0, 9);
			if (nickname == ite->second.getNickName())
			{
				std::cerr << RED << ERR_NICKNAMEINUSE(_name, nickname) << RESET << std::endl;
				client.getBuf().clear();
				return ;
			}
		}	
		std::string str = "Your nickname is now " + nickname + "\r\n";
		client.setNickName(nickname);
		send(client.getSocket(), str.c_str(), str.size(), 0);
	}
	else {
		std::cerr << RED << ERR_NOTREGISTERED(_name) << RESET << std::endl;
		std::cerr << RED << "Enter PASS, NICK, USER in this order" << RESET <<std::endl;
	}
}

void	Server::nickIrssi(Client &client, int i){
	for (std::map<int, Client>::iterator ite = clientsManage.begin(); ite != clientsManage.end(); ite++)
	{
		if (client.getBuf().size() > (size_t)i){
			if (ite->second.getNickName() == client.getBuf()[i + 1]){
				std::stringstream ss;
				ss << _activeClients;
				std::string str = ss.str();
				client.setNickName(client.getBuf()[i + 1] + str);
				return;
			}
		}
	}
	if (client.getBuf().size() > (size_t)i)
		client.setNickName(client.getBuf()[i + 1]);
	else
		client.setNickName("default");	
}