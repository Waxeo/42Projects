#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer( void );
		Serializer( Serializer const &src );
		~Serializer( void );
		Serializer	&	operator=( Serializer const &rhs );
};

#endif