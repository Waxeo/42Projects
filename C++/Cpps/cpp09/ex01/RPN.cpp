#include "RPN.hpp"

void    RPN::stack_management(std::string to_add)
{
    if (to_add.size() != 1)
        throw TwodigitnumberException();
    if (to_add[0] >= '0' && to_add[0] <= '9')
        this->_calcul.push(std::atoi(to_add.c_str()));
    else
        operation(to_add);
}

RPN::RPN( char *operation )
{
    int i = 1;
    std::string input = operation;
    size_t pos = 0;
    std::string token;

    while (pos != std::string::npos)
    {
        pos = input.find(' ');
        if (pos != std::string::npos) 
        {
            token = input.substr(0, pos);
            stack_management(token);
            input.erase(0, pos + 1);
        }
        i++; 
    }

    stack_management(input);

    int res = 0;

    if (!_calcul.empty())
    {
        res = _calcul.top();
        _calcul.pop();
    }
    if (!_calcul.empty())
        throw NumbersleftinstackException();

    std::cout << res << std::endl;
}


RPN::~RPN( void )
{
    return ;
}

void    RPN::operation( std::string ope )
{
    int right = 0;
    int left = 0;
    int res = 0;

    if (!_calcul.empty())
    {
        right = _calcul.top();
        _calcul.pop();
    }
    else
        throw Lessthan2numbersException();
    
    if (!_calcul.empty())
    {
        left = _calcul.top();
        _calcul.pop();
    }
    else
        throw Lessthan2numbersException();
    
    switch (ope[0])
    {
        case '+':
            res = left + right;
            break ;

        case '-':
            res = left - right;
            break ;

        case '*':
            res = left * right;
            break ;

        case '/':
            res = left / right;
            break ;
        default:
                throw BadcharException();
    }

    _calcul.push(res);
}

const char* RPN::Lessthan2numbersException::what() const throw()
{
	return "Calcul is not possible because there are less than 2 numbers";
}

const char* RPN::NumbersleftinstackException::what() const throw()
{
	return "Stack still contains more than one number at the end of the calcul";
}

const char* RPN::BadcharException::what() const throw()
{
	return "Char is not a number or an operator";
}

const char* RPN::TwodigitnumberException::what() const throw()
{
	return "Numbers must contain only one digit";
}