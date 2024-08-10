#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Random ShrubberyCreationForm", 145, 137), _Target("home")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("Random ShrubberyCreationForm", 145, 137), _Target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src )
{
	*this = src;

	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs )
{
	if (this != &rhs)
		this->_Target = rhs._Target;

	return *this;
}

void ShrubberyCreationForm::exec( void ) const
{
	std::string ofstring = _Target + "_shrubbery";
		
	std::ofstream ofs;
	ofs.open(ofstring.c_str(), std::fstream::out | std::fstream::app);
	if (!ofs.is_open())
	{
		std::cout << "Failed to open the _shrubbery" << std::endl;
		return ;
	}

	ofs << _shrubbery1 << std::endl;


	return ;
}

std::string const ShrubberyCreationForm::_shrubbery1 =
"\n"
"                %%%,%%%%%%%\n"
"                 ,'%% \\-%%%%%%%\n"
"           ;%%%%%%   %%%%\"\n"
"            ,%%%       \\(.%%%%.\n"
"            %%%, ,%%%%(    '\n"
"          %^     ,%%% )\\|,%%*%,\n"
"               %    \\/ #).-\"%%\n"
"                   _.) ,/%,\n"
"           _________/)#(__________\n\n";