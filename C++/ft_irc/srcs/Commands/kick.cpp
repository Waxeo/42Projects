#include "Server.hpp"
#include "utils.hpp"

void	Server::kick(Client &client) {
	std::string err;
	if (client.getBuf().size() < 4) {
		err = ERR_NEEDMOREPARAMS(client.getHost(), client.getBuf()[0]);
		send(client.getSocket(), err.c_str(), err.size(), 0);
		return ;
	}
	if (searchClientChannel(client) != 2){
		err = ERR_NOSUCHCHANNEL(client.getBuf()[1]);
		send(client.getSocket(), err.c_str(), err.size(), 0);
		return ;
	}
	if (is_on_channel(client, client.getBuf()[1])) {
		err = ERR_NOTONCHANNEL(getClientChannel(client.getChannel()).getName());
		send(client.getSocket(), err.c_str(), err.size(), 0);
		return ;
	}
	if (is_op(client, client.getNickName()) == -1){
		err = ERR_CHANOPRIVSNEEDED(getClientChannel(client.getChannel()).getName());
		send(client.getSocket(), err.c_str(), err.size(), 0);
		return ;
	}
	for (size_t i = 0; i < getClientChannel(client.getChannel()).getUsers().size(); i++) {
		if (client.getBuf()[2] == getClientChannel(client.getChannel()).getUsers()[i]) {
			err = RPL_KICK(getClientChannel(client.getChannel()).getName(), client.getNickName(), client.getBuf()[2], client.getBuf()[3]);
			send(client.getSocket(), err.c_str(), err.size(), 0);
			for (size_t j = 0; j < clientsManage.size(); j++) {
				if (client.getBuf()[2] == clientsManage[j].getNickName())
					clientsManage[j].getChannel().clear();
			}
			getClientChannel(client.getChannel()).getUsers().erase(getClientChannel(client.getChannel()).getUsers().begin() + i);
			i--;
		}
	}
}

