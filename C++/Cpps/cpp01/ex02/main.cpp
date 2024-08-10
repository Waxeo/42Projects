#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr = &str;
    std::string &ref = str;

    std::cout << "Adresses :" << std::endl;
    std::cout << "str : " << &str << std::endl;
    std::cout << "ptr : "<< ptr << std::endl;
    std::cout << "ref : "<< &ref << std::endl;


    std::cout << "Valeurs :" << std::endl;
    std::cout << "str : "<< str << std::endl;
    std::cout << "ptr : "<< *ptr << std::endl;
    std::cout << "ref : "<< ref << std::endl;
}
