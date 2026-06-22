#include "Whatever.hpp"
#include <iostream>				// ostream


int	main ( void )
{
	int	a = 42;
	int b = 21;

	std::cout << "org a: " << a << std::endl;
	std::cout << "org b: " << b << std::endl;
	::swap(a, b);
	std::cout << "swap a: " << a << std::endl;
	std::cout << "swap b: " << b << std::endl;
	std::cout << "min: " << ::min(a, b) << std::endl;
	std::cout << "max: " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}