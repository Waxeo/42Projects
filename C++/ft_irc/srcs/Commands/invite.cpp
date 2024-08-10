#include "Server.hpp"
#include "utils.hpp"

void	Server::invite(Client &client){
	std::string err;
	if (client.getBuf().size() < 3) {
		err = ERR_NEEDMOREPARAMS(client.getHost(), client.getBuf()[0]);
		send(client.getSocket(), err.c_str(), err.size(), 0);
		return ;
	}
	if (is_op(client, client.getNickName()) == -1){
		err = ERR_CHANOPRIVSNEEDED(getClientChannel(client.getChannel()).getName());
		send(client.getSocket(), err.c_str(), err.size(), 0);
		return ;
	}
	if (is_on_channel(client, client.getBuf()[2])){
		err = ERR_NOTONCHANNEL(getClientChannel(client.getChannel()).getName());
		send(client.getSocket(), err.c_str(), err.size(), 0);
		return ;
	}
	if (searchClientChannel(client) != 1){
		err = ERR_NOSUCHNICK(client.getBuf()[1]);
		send(client.getSocket(), err.c_str(), err.size(), 0);
		return ;
	}
	size_t i;
	for (i = 0; i < getClientChannel(client.getChannel()).getUsers().size(); i++) {
		if (client.getBuf()[1] ==  getClientChannel(client.getChannel()).getUsers()[i])
			break ;
	}
	if (i != getClientChannel(client.getChannel()).getUsers().size()) {
		err = ERR_USERONCHANNEL(client.getBuf()[1], client.getBuf()[2]);
		send(client.getSocket(), err.c_str(), err.size(), 0);
		return ;
	}

	getClientChannel(client.getChannel()).getInvite().push_back(client.getBuf()[1]);
	err = RPL_INVITING(client.getBuf()[2], client.getBuf()[1]);
	send(client.getSocket(), err.c_str(), err.size(), 0);
}