#include "Server.hpp"

int		check_chanpswd(Client &client, Channel &channel)
{
	if (!channel.getPass().empty())
	{
		if (!client.getBuf()[2].empty())
		{
			if (client.getBuf()[2] == channel.getPass())
				return 0;
			else
				return 1;
		}
		return 1;
	}
	return 0;
}

void	joinChannel(Client &client, Channel &channel) {
	if (channel.getL() != 0 && channel.getUsers().size() >= channel.getL()) {
		std::string err = ERR_CHANNELISFULL(channel.getName());
		send(client.getSocket(), err.c_str(), err.size(), 0);
		return ;
	}
	if (channel.getI() == true)
	{
		size_t i;
		for	(i = 0; i < channel.getInvite().size(); i++)
		{
			if (client.getNickName() == channel.getInvite()[i]) {
				break ;
			}
		}
		if (i == channel.getInvite().size()) {
			std::string err = ERR_INVITEONLYCHAN(channel.getName());
			send(client.getSocket(), err.c_str(), err.size(), 0);
			return ;
		}

	}
	if (check_chanpswd(client, channel)) {
		std::string err = ERR_BADCHANNELKEY(channel.getName());
		send(client.getSocket(), err.c_str(), err.size(), 0);
		return ;
	}
	channel.getUsers().push_back(client.getNickName());
	std::string rpl;
	if (channel.getTopic().size() > 0)
		rpl = RPL_TOPIC(channel.getName(), channel.getTopic());
	else
		rpl = RPL_NOTOPIC(channel.getName());
	client.setChannel(channel);
	send(client.getSocket(), rpl.c_str(), rpl.size(), 0);
}

void	Server::join(Client& client) {
	if (client.getBuf().size() == 1) {
		std::cerr << RED << ERR_NEEDMOREPARAMS(_name, client.getBuf()[0]) << RESET << std::endl;
		return ;
	}

	std::string channelName = client.getBuf()[1];
	if (client.getBuf().size() > 2)
		std::string password = client.getBuf()[2];

	if (channelName[0] != '#' && channelName[0] != '&' && channelName[0] != '1')
		channelName.insert(0, "#");

	if (channelName.find(',') != std::string::npos || channelName.find(' ') != std::string::npos){
		std::cerr << RED << (channelName) << RESET << std::endl;
		return ;
	}

	for	(int i = 0; i < _activeChannels; i++)
	{
		if (channelName == _channelsList[i].getName())
		{
			if (client.getBuf().size() > 3) {
				std::string err = ERR_BADCHANNELKEY(_channelsList[i].getName());
				send(client.getSocket(), err.c_str(), err.size(), 0);
				return ;
			}
			joinChannel(client, _channelsList[i]);
			return ;
		}
	}
	if (client.getBuf().size() > 3) {
		std::string err = ERR_BADPASS(_name);
		send(client.getSocket(), err.c_str(), err.size(), 0);
		return ;
	}	
	if (channelName.size() > 32)
		channelName = channelName.substr(0, 32);
	Channel channel(channelName, client.getNickName());
	_channelsList.push_back(channel);
	_activeChannels++;
	joinChannel(client, _channelsList[_channelsList.size() - 1]);
}