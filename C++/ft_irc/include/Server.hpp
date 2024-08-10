#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <cctype>
# include <cstdlib>
# include <cstring>
# include <csignal>
# include <poll.h>
# include <vector>
# include <map>
# include <sstream>
# include "Client.hpp"
# include "Channel.hpp"
# include "utils.hpp"

# define MAX_CLIENTS 5

class Server {
	private:
		Server();

		int	_socket;
		int	_port;
		int _pollRet;
		int _activeClients;
		int _activeChannels;

		std::string _name;
		std::string	_password;

		sockaddr_in _addr;
		socklen_t _size;
		pollfd _fds[MAX_CLIENTS + 1];

		typedef void (Server::*CommandFunction)(Client&);
    	std::map<std::string, CommandFunction> commands;
		std::map<int, Client> clientsManage;
		std::vector<Channel> _channelsList;

		bool	_shutdown;

	public:
		~Server();
		Server(int port, std::string pass);

		void	process();
		void	closeSocket();
		void	createClient();
		void	deleteClient(Client client);
		void	listenClient();
		void	initCommands();
		void	applyCommand(Client &client);

		void	cap(Client &client);
		void	nick(Client &client);
		void	user(Client &client);
		void	pass(Client &client);
		void	pong(Client &client);
		void	mode(Client &client);
		void	privmsg(Client &client);
		void	quit(Client &client);
		void	join(Client &client);
		void	topic(Client &client);
		void	invite(Client &client);
		void	kick(Client &client);

		void	nickIrssi(Client &client, int i);
		void	userIrssi(Client &client, int i);
		bool	passIrssi(Client &client, int i);

		std::string	ft_toupper(std::string str);
		int		searchClientChannel(Client &client);
		int		is_op(Client &client, std::string nickname);
		int		operator_mode(Client &client);
		int		is_on_channel(Client &client, std::string channel);
		int		key_mode(Client &client);
		int		max_client_mode(Client &client);
		void	invite_mode(Client &client);
		void	topic_mode(Client &client);
		void	delete_client_chan(Client &client);
		Channel &getClientChannel(std::string channel);
		void	send_all(Channel &channel, std::string rpl, std::string client);


};

#endif