#include "Server.hpp"
#include "utils.hpp"

int	searchMode(std::string *tab, std::string search, int size){
	for (int i = 0; i < size; i++){
		if (search == tab[i])
			return i;
	}
	return -1;
}

int Server::searchClientChannel(Client &client){
	
	for (std::map<int, Client>::iterator ite = clientsManage.begin(); ite != clientsManage.end(); ite++)
	{
		if (ite->second.getNickName() == client.getBuf()[1])
			return 1;
	}
	for (std::vector<Channel>::iterator ite = _channelsList.begin(); ite != _channelsList.end(); ite++)
	{
		if (ite->getName() == client.getBuf()[1])
			return 2;
	}
	return 0;
}

void	invisible_mode(Client &client){
	std::string ret;
		if (client.getBuf()[2] == "+i" && client.getMode() == false)
		{
			client.setMode(true);
			ret = MODE_USERMSG(client.getNickName(), "+i");
			send(client.getSocket(), ret.c_str(), ret.size(), 0);
		}
		else if (client.getBuf()[2] == "-i" && client.getMode() == true)
		{
			client.setMode(false);
			ret = MODE_USERMSG(client.getNickName(), "-i");
			send(client.getSocket(), ret.c_str(), ret.size(), 0);
		}
}

void	Server::invite_mode(Client &client){
	std::string ret;
	if (client.getBuf()[2] == "+i" && getClientChannel(client.getChannel()).getI() == false)
	{
		getClientChannel(client.getChannel()).setI(true);
		ret = MODE_CHANNELMSG(getClientChannel(client.getChannel()).getName(), "+i");
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
	}
	else if (client.getBuf()[2] == "-i" && getClientChannel(client.getChannel()).getI() == true)
	{
		getClientChannel(client.getChannel()).setI(false);
		ret = MODE_CHANNELMSG(getClientChannel(client.getChannel()).getName(), "-i");
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
	}
}

void	Server::topic_mode(Client &client){
	std::string ret;
	if (client.getBuf()[2] == "+t" && getClientChannel(client.getChannel()).getT() == false)
	{
		getClientChannel(client.getChannel()).setT(true);
		ret = MODE_CHANNELMSG(getClientChannel(client.getChannel()).getName(), "+t");
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
	}
	else if (client.getBuf()[2] == "-t" && getClientChannel(client.getChannel()).getT() == true)
	{
		getClientChannel(client.getChannel()).setT(false);
		ret = MODE_CHANNELMSG(getClientChannel(client.getChannel()).getName(), "-t");
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
	}
}

int	Server::key_mode(Client &client){
	std::string ret;
	if (client.getBuf()[2] == "+k")
	{
		if (client.getBuf().size() == 4)
			getClientChannel(client.getChannel()).setPass(client.getBuf()[3]);
		else if (client.getBuf().size() > 4) {
			ret = ERR_BADPASS(client.getHost());
			send(client.getSocket(), ret.c_str(), ret.size(), 0);
			return 1;
		}
		else {
			ret = ERR_NEEDMOREPARAMS(client.getHost(), client.getBuf()[0]);
			send(client.getSocket(), ret.c_str(), ret.size(), 0);
			return 1;
		}

		ret = MODE_CHANNELMSG(getClientChannel(client.getChannel()).getName(), "+k");
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
	}
	else if (client.getBuf()[2] == "-k")
	{
		getClientChannel(client.getChannel()).getPass().clear();
		ret = MODE_CHANNELMSG(getClientChannel(client.getChannel()).getName(), "-k");
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
	}
	return 0;
}

int	Server::max_client_mode(Client &client){
	std::string ret;
	if (client.getBuf()[2] == "+l")
	{
		if (client.getBuf()[3].size() > 10)
		{
			std::string err = ERR_BADMODEL(client.getHost());
			send(client.getSocket(), err.c_str(), err.size(), 0);
			return 1;
		}
		long long l = std::atoi(client.getBuf()[3].c_str());
		if (l < 1 || l > 2147483647)
		{
			std::string err = ERR_BADMODEL(client.getHost());
			send(client.getSocket(), err.c_str(), err.size(), 0);
			return 1;
		}
		getClientChannel(client.getChannel()).setL(l);
		ret = MODE_CHANNELMSG(getClientChannel(client.getChannel()).getName(), "+l");
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
	}
	else if (client.getBuf()[2] == "-l")
	{
		getClientChannel(client.getChannel()).setL(0);
		ret = MODE_CHANNELMSG(getClientChannel(client.getChannel()).getName(), "-l");
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
	}
	return 0;
}

int	Server::operator_mode(Client &client){
	
	std::string ret;
	if (client.getBuf().size() < 4){
		ret = ERR_NEEDMOREPARAMS(client.getHost(), client.getBuf()[0]);
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
		return 1;
	}
	if (client.getBuf()[2] == "+o" && is_op(client, client.getBuf()[3]) == -1)
	{
		for (size_t i = 0; i < getClientChannel(client.getChannel()).getUsers().size(); i++)
		{
			if (client.getBuf()[3] ==  getClientChannel(client.getChannel()).getUsers()[i])
			{
				getClientChannel(client.getChannel()).getOperator().push_back(client.getBuf()[3]);
				ret = MODE_CHANNELMSG(getClientChannel(client.getChannel()).getName(), "+o");
				send(client.getSocket(), ret.c_str(), ret.size(), 0);
				return 1;
			}
		}
		ret = ERR_USERNOTINCHANNEL(getClientChannel(client.getChannel()).getName() ,client.getBuf()[3]);
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
		return 1;
	}
	else if (client.getBuf()[2] == "-o" && is_op(client, client.getBuf()[3]) == 1) {
		for (std::vector<std::string>::iterator ite = getClientChannel(client.getChannel()).getOperator().begin(); ite != getClientChannel(client.getChannel()).getOperator().end(); ite++) {
			std::cout << *ite << std::endl;
			std::cout << client.getBuf()[3] << std::endl;
			if (client.getBuf()[3] == *ite) {
				getClientChannel(client.getChannel()).getOperator().erase(ite);
				ret = MODE_CHANNELMSG(getClientChannel(client.getChannel()).getName(), "-o");
				send(client.getSocket(), ret.c_str(), ret.size(), 0);
				break;
			}
		}
	}
	return 0;
}

void	Server::mode(Client &client) {
	if (client.getBuf().size() == 2 && client.getBuf()[1] == client.getNickName()){
		std::string mode = "+";
		if (client.getMode())
			mode += "i";	
		std::string ret = RPL_UMODEIS(client.getNickName(), mode);
		send(client.getSocket(), ret.c_str(), ret.size(), 0);
		return ;
	}
	int search = searchClientChannel(client);
	if (search == 1)
		invisible_mode(client);
	if (search == 2)
	{
		int i;
		for (size_t ite = 0; ite < _channelsList.size(); ite++)
		{
			if (_channelsList[ite].getName() == client.getBuf()[1])
				i = ite;
		}
		if (is_on_channel(client, client.getBuf()[1])) {
			std::string err = ERR_NOTONCHANNEL(getClientChannel(client.getChannel()).getName());
			send(client.getSocket(), err.c_str(), err.size(), 0);
			return ;
		}
		if (is_op(client, client.getNickName()) == -1){
			std::string err = ERR_CHANOPRIVSNEEDED(getClientChannel(client.getChannel()).getName());
			send(client.getSocket(), err.c_str(), err.size(), 0);
			return ;
		}
		if (client.getBuf()[2] == "+i" || client.getBuf()[2] == "-i")
			invite_mode(client);

		if (client.getBuf()[2] == "+t" || client.getBuf()[2] == "-t")
			topic_mode(client);

		if (client.getBuf()[2] == "+k" || client.getBuf()[2] == "-k"){
			if (key_mode(client))
				return ;
		}

		if (client.getBuf()[2] == "+l" || client.getBuf()[2] == "-l"){
			if (max_client_mode(client))
				return ;
		}

		if (client.getBuf()[2] == "+o" || client.getBuf()[2] == "-o")
		{
			if (operator_mode(client))
				return ;
		}
	}
}

/*

— i : Définir/supprimer le canal sur invitation uniquement -- /!\ au i du user != i du canal
	
*/