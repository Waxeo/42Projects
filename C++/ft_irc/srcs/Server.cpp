#include "Server.hpp"

Server::Server(){

}

Server::~Server(){

}

Server::Server(int port, std::string pass) : _port(port), _activeClients(0), _activeChannels(0), _name("MyIRC"), _password(pass), _shutdown(false) {
	
	for (size_t i = 0; i < _password.size(); i++) {
		if (_password[i] == 32 || (_password[i] >= 9 && _password[i] <= 13))
			throw (std::runtime_error("Invalid password."));
	}
	
	_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (_socket == -1) {
		throw (std::runtime_error("Server socket error."));
	}

	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(_port);
	_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	_size = sizeof(sockaddr_in);

	int reuse = 1;
	if (setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
		close(_socket);
		throw (std::runtime_error("Error setting socket options."));
	}

	if (bind(_socket, (struct sockaddr *)&_addr, _size) == -1) {
        close(_socket);
       	throw (std::runtime_error("Error binding server."));

    }

	if (listen(_socket, MAX_CLIENTS) == -1) {
        close(_socket);
        throw (std::runtime_error("Error listening connexion."));
    }

	memset(_fds, 0, sizeof(_fds));
	_fds[0].fd = _socket;
	_fds[0].events = POLLIN;
	initCommands();
	std::cout << WHITE_BOLD << _name << " server started on port " << _port << RESET << std::endl;
}

void	Server::process() {
	while (_shutdown == false) {
		_pollRet = poll(_fds, _activeClients + 1, -1);
		if (_pollRet == -1){
			closeSocket();
			throw (std::runtime_error("Failed poll()."));
		}

		if (_fds[0].revents & POLLIN)
			createClient();

		listenClient();
	}
}

void	Server::createClient(){
	sockaddr_in clientAddr;
	socklen_t clientSize = sizeof(sockaddr_in);
	int clientSocket = accept(_socket, (sockaddr *)&clientAddr, &clientSize);
	if (clientSocket == -1)
	    std::cerr << RED << "Error client connection" << RESET << std::endl;        
	else {
		if (_activeClients < MAX_CLIENTS){
			Client client(clientSocket, clientAddr);
			_activeClients++;
			client.setId(_activeClients);
			clientsManage[clientSocket] = client;
			_fds[_activeClients].fd = clientSocket;
			_fds[_activeClients].events = POLLIN;

			send(clientSocket, "Welcome to IRC Server!\n", 23, 0);
		} else {
			std::cerr << RED << "Max clients number reach" << RESET << std::endl;
			close(clientSocket);
		}
	}
}

void	Server::listenClient() {
	for (int i = 1; i <= _activeClients; i++) {
		if (_fds[i].revents & POLLIN) {
			char buffer[1024];
			int bytesRead = recv(_fds[i].fd, buffer, sizeof(buffer) - 1, 0);
			if (bytesRead > 0) {
				buffer[bytesRead] = '\0';
				clientsManage[_fds[i].fd].setBuf(buffer);
				if (strstr(buffer, "\r\n")) {
					applyCommand(clientsManage[_fds[i].fd]);
					clientsManage[_fds[i].fd].getBuf().clear();
				}
			}
			else {
				delete_client_chan(clientsManage[_fds[i].fd]);
				deleteClient(clientsManage[_fds[i].fd]);
				i--;
			}
		}
		// else if (_fds[i].revents & POLLOUT) {
		// 	if (clientsManage[_fds[i].fd].getDeco()){
		// 		clientsManage[_fds[i].fd].getBuf().clear();
		// 		deleteClient(clientsManage[_fds[i].fd]);
		// 		break;
		// 	}
		// }
	}
}

void	Server::deleteClient(Client client) {
	std::map<int, Client>::iterator it = clientsManage.find(client.getSocket());
	if (it != clientsManage.end()){		
		close(client.getSocket());
		std::cout << CYAN << "Client " << client.getId() << " disconnected" << RESET << std::endl;
		clientsManage.erase(it);
		_activeClients--;
	}
	for (int j = client.getId(); j <= _activeClients; ++j)
		_fds[j] = _fds[j + 1];	
}

void	Server::cap(Client &client){
	if (client.getIrssi() == false){
		bool passw = false;
		for (size_t i = 0; i < client.getBuf().size(); i++){
			if (client.getBuf()[i] == "PASS")
				passw = passIrssi(client, i);
			if (client.getBuf()[i] == "NICK")
				nickIrssi(client, i);
			if (client.getBuf()[i] == "USER")
				userIrssi(client, i);
		}
		if (passw) {
			client.setRpl(RPL_WELCOME(user_id(client.getUserName(), client.getNickName()), client.getNickName()));
			send(client.getSocket(), client.getRpl().c_str(), client.getRpl().size(), 0);
			std::cout << GREEN << "Client " << client.getId() << " connected" << RESET << std::endl;
			client.setIrssi();
			client.setVerif();
		}
	}
	else
		std::cerr << RED << ERR_UNKNOWNCOMMAND(client.getBuf()[0]) << RESET << std::endl;		
}