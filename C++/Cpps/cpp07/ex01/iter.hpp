#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <iomanip>
#include <string>

template <typename T>
void iter(T *array, size_t size, void (*f)(T&))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
	return ;
}

template <typename T>
void plus_one(T &c)
{
	c++;
	return ;
}

#endif
