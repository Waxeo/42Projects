#include "Client.hpp"
#include "utils.hpp"

Client::Client() {

}

Client::~Client(){

}

Client::Client(int sock, sockaddr_in addr) :_socket(sock), _id(0), _addr(addr), _host("localhost"), \
	_invisible(false), _irssi(false), _verified(false), _deco(false) {

}

Client::Client(const Client& cpy) : _socket(cpy._socket), _id(cpy._id), _addr(cpy._addr),  _nickName(cpy._nickName), _userName(cpy._userName), \
	_host(cpy._host), _pass(cpy._pass),_rpl(cpy._rpl), _buf(cpy._buf), \
		_invisible(cpy._invisible), _irssi(cpy._irssi), _verified(cpy._verified), _deco(cpy._deco){

}

Client & Client::operator=(Client const & cpy) {
	if (this != &cpy){
		this->_socket = cpy._socket;
		this->_id = cpy._id;
		this->_addr = cpy._addr;
		this->_nickName = cpy._nickName;
		this->_userName = cpy._userName;
		this->_host = cpy._host;
		this->_pass = cpy._pass;
		this->_rpl = cpy._rpl;
		this->_buf = cpy._buf;
		this->_invisible = cpy._invisible;
		this->_irssi = cpy._irssi;
		this->_verified = cpy._verified;
		this->_deco = cpy._deco;
	}
	return *this;
}


void	Client::setBuf(const std::string buffer)
{
	std::istringstream iss(buffer);
    std::string token;

    while (iss >> token) {
		_buf.push_back(token);
	}
}

void	Client::setVerif(){
	_verified = true;
}
