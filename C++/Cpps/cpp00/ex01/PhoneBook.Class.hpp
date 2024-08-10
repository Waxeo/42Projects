#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Contact.Class.hpp"

class PhoneBook
{
	private:
   		Contact	_contacts[8];
	public:
    	PhoneBook();
    	~PhoneBook();
        int		add_new(int index);
		void	search(int index) const;
};

#endif