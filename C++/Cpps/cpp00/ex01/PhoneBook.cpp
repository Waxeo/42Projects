#include "PhoneBook.Class.hpp"
#include "Contact.Class.hpp"

PhoneBook::PhoneBook()
{
	std::cout << CYAN << "--Welcome to my awesome PhoneBook--" << RESET << std::endl
			  << "The commands you can use are ADD, SEARCH or EXIT." << std::endl
			  << "Have fun!" << std::endl;
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Erasing PhoneBook Data" << std::endl;
	return ;
}

static bool isNumeric(std::string const &str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}

int	PhoneBook::add_new(int index)
{
	std::string first_name, last_name, nickname, phone_number, darkest_secret;

	std::cout << YELLOW << "You are adding a new contact to the PhoneBook," << std::endl \
	<< "Please enter your first name : " << RESET;

//	first name	
	std::getline(std::cin, first_name);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return index;
	}
	while (first_name.empty())
	{
		std::cout << RED << "Error encontred : Empty Field, try again" << RESET << std::endl;
		std::cout << YELLOW << "Please enter your first name : " << RESET;
		std::getline(std::cin, first_name);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return index;
		}
	}

//	last name
	std::cout << YELLOW << "Enter your last name : " << RESET;
	std::getline(std::cin, last_name);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return index;
	}
	while (last_name.empty())
	{
		std::cout << RED << "Error encontred : Empty Field, try again" << RESET << std::endl;
		std::cout << YELLOW << "Enter your last name : " << RESET;
		std::getline(std::cin, last_name);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return index;
		}	
	}


//	nickname
	std::cout << YELLOW << "Choose a nickname : " << RESET;
	std::getline(std::cin, nickname);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return index;
	}
	while (nickname.empty())
	{
		std::cout << RED << "Error encontred : Empty Field, try again" << RESET << std::endl;
		std::cout << YELLOW << "Choose a nickname : " << RESET;
		std::getline(std::cin, nickname);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return index;
		}
	}


//	phonenumber
	std::cout << YELLOW << "Enter your phone number : " << RESET;
	std::getline(std::cin, phone_number);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return index;
	}
	while (!isNumeric(phone_number))
	{
		std::cout << RED << "Non-Numeric phone number or empty field, try again" << RESET << std::endl;
		std::cout << YELLOW << "Enter your phone number : " << RESET;
		std::getline(std::cin, phone_number);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return index;
		}	
	}

	
//	darkest secret
	std::cout << YELLOW << "Tell me your darkest secret : " << RESET;
	std::getline(std::cin, darkest_secret);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return index;
	}
	while (darkest_secret.empty())
	{
		std::cout << RED << "Error encontred : Empty Field, try again" << RESET << std::endl;
		std::cout << YELLOW << "Tell me your darkest secret : " << RESET;
		std::getline(std::cin, darkest_secret);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return index;
		}
	}

	_contacts[index % 8].setprivate(first_name, last_name, nickname, phone_number, darkest_secret);
	index++;

	return (index);
}

static	int	stringToInt(const std::string& str)
{
    std::istringstream iss(str);
    int value = 0;
    iss >> value;
    return (value);
}

void	PhoneBook::search(int index) const
{
	int i = -1;
	std::string	user;

	std::cout << RED << std::setfill('_') << std::setw(45) << "" << std::setfill(' ') << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "" << std::setfill(' ')  << RESET << std::endl;

	while (++i < index && i <= 7)
		_contacts[i % 8].aff_tab(i);

	if (index == 0)
	{
		std::cout << "No contact added to the phonebook" << std::endl;
		return ;
	}
	
	std::cout << "Please select contact index : ";
	std::getline(std::cin, user);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return ;
	}

	while (!isNumeric(user))
	{
		std::cout << RED << "Non-Numeric index, try again" << RESET << std::endl;
		std::cout << "Please select contact index : ";
		std::getline(std::cin, user);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
	}
	i = stringToInt(user);
	if (i < 0 || i >= index)
	{
		std::cout << "Contact #" << i << " do not exist" << std::endl;
		return ;
	}
	_contacts[i].aff_usr(i);

	return ;
}
