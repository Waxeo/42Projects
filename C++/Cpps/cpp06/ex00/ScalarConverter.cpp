#include "ScalarConverter.hpp"

bool	isChar(std::string base)
{
	if (base.size() != 1)
		return false;
	
	if (base[0] >= 65 && base[0] <= 90)
		return true;

	if (base[0] >= 97 && base[0] <= 122)
		return true;

	return false;
}

bool	isInt(std::string base)
{
	size_t minus = 0;

	if (base[minus] == 45)
		minus++;

	for (size_t i = 0 + minus; i < base.size(); i++)
	{
		if (!isdigit(base[i]))
			return false;
	}
	

	char* endptr;
    errno = 0;
    long long int value = strtoll(base.c_str(), &endptr, 10);

    // Vérifier si la conversion a échoué ou si des caractères non valides existent dans la chaîne
    if (errno != 0 || *endptr != '\0') {
        return false;
    }

    // Vérifier les limites de int
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
        return false;
    }

	return true;

}

bool	isFloat(std::string base)
{
	size_t minus = 0;
	int	dot = 0;

	if (base[minus] == 45 || base[minus] == 43)
		minus++;

	for	(size_t i = 0 + minus; i < base.size(); i++)
	{
		if (!isdigit(base[i]) && base[i] != 46 && base[i] != 102)
			return false;
		if (base[i] == 46 && isdigit(base[i - 1]))
			dot++;
	}

	if (dot != 1)
		return false;
	if (base[base.size() - 1] != 102 || !isdigit(base[base.size() - 2]))
		return false;
	return true;
}

bool	isDouble(std::string base)
{
	size_t	i = 0; 
	int	dot = 0;

	if (base[i] == 45 || base[i] == 43)
		i++;
	for	(size_t x = 0 + i; x < base.size(); x++)
	{
		if (!isdigit(base[x]) && base[x] != 46)
			return false;
		if (base[x] == 46 && isdigit(base[x - 1]))
			dot++;
	}
	if (dot != 1)
		return false;
	if (!isdigit(base[base.size() - 1]))
		return false;
	return true;
}


int	typeFinder(std::string base)
{
	if (base.size() == 1)
	{
		if (base[0] >= '0' && base[0] <= '9')
			return 2;
		else
			return 1;
	}

	if (isInt(base) == true)
		return 2;
	
	if (isFloat(base) == true)
		return 3;

	if (isDouble(base) == true)
		return 4;

	return -1;
}

bool	check_particular(std::string base)
{
	float particular = 0.0f;
	double particular2 = 0.0f;

	if (!base.compare("nanf") || !base.compare("nan"))
	{
		particular = std::numeric_limits<float>::quiet_NaN();
		particular2 = std::numeric_limits<double>::quiet_NaN();

		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << particular << "f" << std::endl;
		std::cout << "double : " << particular2 << std::endl;
		
		return true;
	}

	if (!base.compare("-inff") || !base.compare("-inf"))
	{
		particular = -std::numeric_limits<float>::infinity();
		particular2 = -std::numeric_limits<double>::infinity();


		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << particular << "f" << std::endl;
		std::cout << "double : " << particular2 << std::endl;

		return true;
	}

	if (!base.compare("+inff") || !base.compare("+inf"))
	{
		particular = std::numeric_limits<float>::infinity();
		particular2 = std::numeric_limits<double>::infinity();


		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << particular << "f" << std::endl;
		std::cout << "double : " << particular2 << std::endl;

		return true;
	}
	return false;
}

void	ScalarConverter::convert(std::string base)
{
	int type = typeFinder(base);
	char char_ = '\0';
	int	int_ = 0;
	float float_ = 0.0f;
	double double_ = 0.0;

	if (check_particular(base))
		return;
	switch (type)
	{
		case 1:
			char_ = base[0];
			int_ = static_cast<int>(char_);
			float_ = static_cast<float>(char_);
			double_ = static_cast<double>(char_);
			break;

		case 2:
			int_ = std::atoi(base.c_str());
			char_ = static_cast<char>(int_);
			float_ = static_cast<float>(int_);
			double_ = static_cast<double>(int_);
			break;

		case 3:
			float_ = static_cast<float>(std::atof(base.c_str()));
			char_ = static_cast<char>(float_);
			int_ = static_cast<int>(float_);
			double_ = static_cast<double>(float_);
			break;

		case 4:
			double_ = std::atof(base.c_str());
			char_ = static_cast<char>(double_);
			int_ = static_cast<int>(double_);
			float_ = static_cast<float>(double_);
			break;

		default:
			std::cout << "Wrong argument." << std::endl;
			break;

	}

	if (isprint(char_))
		std::cout << "char : '" << char_ << "'" << std::endl;
	else 
		std::cout << "char : non-printable" << std::endl;
	
	if (double_ > std::numeric_limits<int>::max() || double_ < std::numeric_limits<int>::min())
		std::cout << "int : overflow" << std::endl;
	else
		std::cout << "int : " << int_ << std::endl;
	std::cout << "float : " << float_ << ".0f" << std::endl;
	std::cout << "double : " << double_ << ".0" << std::endl;

	return ;
}





