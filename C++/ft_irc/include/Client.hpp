#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <sstream>
# include <vector>
# include <netinet/in.h>
# include <string>
# include <stdexcept>
# include "Channel.hpp"

class Client
{
	private:
		int _socket;
		int	_id;


		sockaddr_in _addr;

		std::string _nickName;
		std::string _userName;
		std::string _host;
		std::string _pass;
		std::string _rpl;

		std::vector<std::string>	_buf;

		std::string 	_activeChannel;

		bool _invisible;
		bool _irssi;
		bool _verified;
		bool _deco;

	public:
		Client();
		Client(const Client& cpy);
		~Client();
		Client(int sock, sockaddr_in addr);

		Client & operator=(Client const & cpy);

		int			getSocket()  const {return _socket;};
		int			getId()  const {return _id;};
		std::string	getNickName() const {return _nickName;};
		std::string	getUserName() const {return _userName;};
		std::string	getPass() const {return _pass;};
		std::string getHost() const {return _host;};
		std::string getRpl() const {return _rpl;};
		bool		getMode() const {return _invisible;};
		bool		getVerif() const {return _verified;};
		bool		getIrssi() const {return _irssi;};
		bool		getDeco() const {return _deco;};
		std::string		&getChannel() {return _activeChannel;};
		std::vector<std::string>	&getBuf() {return _buf;};

		void	setId(int i) {_id = i;};
		void	setNickName(const std::string &nick) {_nickName = nick;};
		void	setUserName(const std::string &user) {_userName = user;};
		void	setPass(const std::string &pass) {_pass = pass;};
		void	setRpl(const std::string &rpl) {_rpl = rpl;};
		void	setMode(bool i) {_invisible = i;};
		void	setVerif();
		void	setDeco() {_deco = true;};
		void	setIrssi() {_irssi = true;};
		void	setChannel(Channel channel) {_activeChannel = channel.getName();};
		void	setBuf(const std::string buffer);


};

#endif