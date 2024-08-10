#include "Server.hpp"

void	Server::quit(Client &client){
	std::string str = RPL_QUIT(user_id(client.getUserName(), client.getNickName()), "Leave");
	send(client.getSocket(), str.c_str(), str.size(), 0);
	client.setDeco();
	delete_client_chan(client);
	deleteClient(client);
}