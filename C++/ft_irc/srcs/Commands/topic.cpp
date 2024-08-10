#include "Server.hpp"


void	Server::topic(Client &client) {

	if (client.getBuf().size() < 2){
		std::string ret = ERR_NEEDMOREPARAMS(client.getHost(), client.getBuf()[0]);
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
	}
	if (is_on_channel(client, client.getBuf()[1]))
		return ;
	if (client.getBuf().size() == 2)
	{
		std::string rpl;
		if (getClientChannel(client.getChannel()).getTopic().size() > 0)
			rpl = RPL_TOPIC(getClientChannel(client.getChannel()).getName(), getClientChannel(client.getChannel()).getTopic());
		else
			rpl = RPL_NOTOPIC(getClientChannel(client.getChannel()).getName());
		send(client.getSocket(), rpl.c_str(), rpl.size(), 0);
	}
	else if (client.getBuf().size() > 2)
	{
		if (getClientChannel(client.getChannel()).getT() == true) {
			if (is_op(client, client.getNickName()) == -1)
				return ;
		}
		
		std::string topic;

		for (size_t i = 2; i < client.getBuf().size(); i++){
			topic += client.getBuf()[i];
			if (i < client.getBuf().size() - 1)
				topic += " ";
		}
		getClientChannel(client.getChannel()).setTopic(topic);
		std::string rpl = RPL_TOPIC(getClientChannel(client.getChannel()).getName(), topic);
		send(client.getSocket(), rpl.c_str(), rpl.size(), 0);
	}
}