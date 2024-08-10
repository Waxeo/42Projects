#include "Span.hpp"

Span::Span( void ) : _N(10)
{
	return ;
}

Span::Span( unsigned int n ) : _N(n)
{
	return ;
}

Span::Span( Span const &src )
{
	*this = src;
	return ;
}

Span::~Span( void )
{
	return ;
}

void	Span::addNumber(int to_add)
{
	if (std::distance(this->_Array.begin(), this->_Array.end()) + 1 > this->_N)
		throw SpanAlreadyFullException();
	else
		this->_Array.push_back(to_add);
	
	return ;
}

int	Span::shortestSpan( void )
{	
	if (this->_Array.size() < 2)
		throw NoSpanException();

	std::sort(this->_Array.begin(), this->_Array.end());

	int span = this->_Array[1] - this->_Array[0];

	for (unsigned long i = 1; i < this->_Array.size(); i++)
		span = std::min(this->_Array[i] - this->_Array[i - 1], span);

	return span;
}

int	Span::longestSpan( void )
{
	if (this->_Array.size() < 2)
		throw NoSpanException();

	std::sort(this->_Array.begin(), this->_Array.end());

	return this->_Array[this->_Array.size() - 1] - this->_Array[0];
}

void	Span::addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, std::vector<int> numbers)
{
	if (numbers.size() > this->_N)
		throw SpanAlreadyFullException();
	
	this->_Array.insert(this->_Array.begin(), begin, end);

	return ;
}

const char* Span::SpanAlreadyFullException::what() const throw()
{
	return "Span size exceeded";
}

const char* Span::NoSpanException::what() const throw()
{
	return "This class contains less than 2 values.";
}