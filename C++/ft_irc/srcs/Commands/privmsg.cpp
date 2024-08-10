#include "Server.hpp"
#include "utils.hpp"

void	Server::privmsg(Client &client){
	std::string ret;
	std::string	message;

	if (client.getBuf().size() < 3) {
		ret = ERR_NEEDMOREPARAMS(client.getHost(), client.getBuf()[0]);
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
		return ;
	}
	
	int b = searchClientChannel(client);

	if (b == 1) {
		for (size_t i = 2; i < client.getBuf().size(); i++){
			message += client.getBuf()[i];
			if (i < client.getBuf().size() - 1)
				message += " ";
		}
		size_t j;
		for (j = 0; j < clientsManage.size(); j++){
			if (client.getBuf()[1] ==  clientsManage[j].getNickName())
				break;
		}
		ret = RPL_PRIV(client.getNickName(), client.getBuf()[1], message);
		send(clientsManage[j].getSocket(), ret.c_str(), ret.size(), 0);
	}
	else if (b == 2) {
		for (size_t i = 2; i < client.getBuf().size(); i++){
			message += client.getBuf()[i];
			if (i < client.getBuf().size() - 1)
				message += " ";
		}
		ret = RPL_PRIV(client.getNickName(), client.getBuf()[1], message);
		send_all(getClientChannel(client.getChannel()), ret, client.getNickName());
	}
	else {
		ret = ERR_NOSUCHNICK(client.getBuf()[1]);
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
	}




}