#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "PhoneBook.Class.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[5;96m"

class Contact
{
    private:
        std::string _FirstName;
        std::string _LastName;
        std::string _NickName;
        std::string _PhoneNumber;
        std::string _DarkestSecret;
    public:
        Contact();
        ~Contact();
        void    setprivate(std::string first_name, std::string last_name, 
                            std::string nick_name, std::string phone_number,
                            std::string DarkestSecret);
        void    aff_tab(int i) const;
		void	aff_usr(int i) const;
};

#endif
