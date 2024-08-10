#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[96m"

template <typename T>
class Array
{
	public:

		Array( void );
		Array( unsigned int n );
		Array( Array const &src);
		~Array( void );

		Array	&	operator=( Array const &rhs );
   		T		&	operator[](unsigned int index) const;

		int	size( void );

		class BadIndex : public std::exception
		{
    		public:
       			virtual const char* what() const throw();
		};

	private:

		T *_Array;
		unsigned int _N;
};

template <typename T>
Array<T>::Array( void ) : _Array(new T[0]()), _N(0)
{
	// std::cout << "Array default constructor called." << std::endl;
	return ;
}

template <typename T>
Array<T>::Array( unsigned int n ) : _Array(new T[n]()), _N(n)
{
	// std::cout << "Array constructor called." << std::endl;
	return ;
}

template <typename T>
Array<T>::Array( Array const &src ) : _N(src._N)
{
	// std::cout << "Array copy constructor called." << std::endl;

	this->_Array = new T[this->_N]();
	
	for (size_t i = 0; i < src._N; i++)
		this->_Array[i] = src._Array[i];

	return ;
}

template <typename T>
Array<T>::~Array( void )
{
	// std::cout << "Array desconstructor called." << std::endl;
	delete [] this->_Array;

	return ;
}

template <typename T>
Array<T>	&Array<T>::operator=( Array const &rhs )
{
	// std::cout << "Array copy operator called." << std::endl;

	delete [] this->_Array;

	if (this != &rhs)
	{
		this->_N = rhs._N;
		this->_Array = new T[rhs._N]();
	}
	for (size_t i = 0; i < rhs._N; i++)
		this->_Array[i] = rhs._Array[i];

	return *this;
}

template <typename T>
T		&Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_N)
		throw BadIndex();

	return this->_Array[index];
}

template <typename T>
int		Array<T>::size( void )
{
	return this->_N;
}

template <typename T>
const char* Array<T>::BadIndex::what() const throw()
{
	return "Bad Index.";
}

#endif