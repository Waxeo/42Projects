#include "Channel.hpp"

Channel::Channel() {

}

Channel::Channel(std::string name, std::string owner) : _name(name), _owner(owner), \
		_i(false), _t(false), _l(0) {
	
	_operator.push_back(_owner);
}

Channel::Channel(const Channel& cpy) : _name(cpy._name), _topic(cpy._topic), _owner(cpy._owner), \
		_i(cpy._i), _t(cpy._t), _l(cpy._l), _operator(cpy._operator), _invite(cpy._invite), _users(cpy._users) {

}

Channel::~Channel() {

}

Channel &Channel::operator=(Channel const & cpy) {
	if (this != &cpy) {
		this->_name = cpy._name;
		this->_topic = cpy._topic;
		this->_owner = cpy._owner;
		this->_i = cpy._i;
		this->_t = cpy._t;
		this->_l = cpy._l;
		this->_operator = cpy._operator;
		this->_invite = cpy._invite;
		this->_users = cpy._users;
	}
	return *this;
}