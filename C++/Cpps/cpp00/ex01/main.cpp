#include "PhoneBook.Class.hpp"
#include "Contact.Class.hpp"

int main()
{
	PhoneBook    book;
	std::string  entry;
	int	index = 0;

    while (!std::cin.eof())
    {
		std::cout << "> ";
        getline(std::cin, entry);
        if (!entry.compare("EXIT"))
        	break ;
        else if (!entry.compare("ADD"))
			index = book.add_new(index);
        else if (!entry.compare("SEARCH"))
            book.search(index);
		else
			std::cout << entry << " : Command not found" << std::endl;
    }
    return (0);
}
