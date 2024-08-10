#include "Server.hpp"
#include "utils.hpp"

void	Server::pong(Client& client) {
	
	std::string pingu = "PONG :localhost\r\n";
	send(client.getSocket(), pingu.c_str(), pingu.size(), 0);
	std::cout << user_id(client.getUserName(), client.getNickName()) << " " << pingu;
}