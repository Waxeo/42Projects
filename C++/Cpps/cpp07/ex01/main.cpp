#include "iter.hpp"

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }

int	main()
{
	std::string test = "abcdefghijklmnopqrstuvwxyz";

	::iter(&test[0], test.size(), plus_one);

	std::cout << test << std::endl;

	int test2[] = { 1, 2, 3, 4};

	::iter(test2, 4, plus_one);

	for (size_t i = 0; i < 4; i++)
		std::cout << test2[i] << " ";
	
	return 0;
}