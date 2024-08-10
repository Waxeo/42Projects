#include "PhoneBook.Class.hpp"
#include "Contact.Class.hpp"

Contact::Contact()
{
    return ;
}
    
Contact::~Contact()
{
    return ;
}

void    Contact::setprivate(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret)
{
	this->_FirstName = first_name;
	this->_LastName = last_name;
	this->_NickName = nick_name;
	this->_PhoneNumber = phone_number;
	this->_DarkestSecret = darkest_secret;
	std::cout << GREEN << "Contact added to the PhoneBook !" << RESET << std::endl;

	return ;
}

void Contact::aff_tab(int i) const
{
	std::cout << RED  << "|" << std::setfill(' ') << std::setw(10) << i << "|";

//	FirstName	
	if (this->_FirstName.size() >= 10)
	{
		std::string	first_name = this->_FirstName.substr(0, 9) + ".";
		std::cout << std::setw(10) << first_name << "|";
	}
	else
		std::cout << std::setw(10) << this->_FirstName << "|";
	
//	LastName
	if (this->_LastName.size() >= 10)
	{
		std::string	last_name = this->_LastName.substr(0, 9) + ".";
		std::cout << std::setw(10) << last_name << "|";
	}
	else
		std::cout << std::setw(10) << this->_LastName << "|";
	
//	NickName
	if (this->_NickName.size() >= 10)
	{
		std::string	nick_name = this->_NickName.substr(0, 9) + ".";
		std::cout << std::setw(10) << nick_name << "|" << std::endl;
	}
	else
		std::cout << std::setw(10) << this->_NickName << "|" << std::endl;


	std::cout << std::setfill('-') << std::setw(45) << "" << std::setfill(' ')  << RESET << std::endl;

	return ;
}

void Contact::aff_usr(int i) const
{
	std::cout << std::endl << "Contact #" << i << " :" << std::endl;
	std::cout << BLUE << "First Name > " << RESET << this->_FirstName << std::endl;
	std::cout << BLUE << "Last Name > " << RESET << this->_LastName << std::endl;
	std::cout << BLUE << "NickName > " << RESET << this->_NickName << std::endl;
	std::cout << BLUE << "Phone Number > " << RESET << this->_PhoneNumber << std::endl;
	std::cout << BLUE << "Darkest Secret > " << RESET << this->_DarkestSecret << std::endl;

	return ;
}
