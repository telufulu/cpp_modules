#include <iostream>		// cout
#include "Whatever.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS				*/
/* ****************************************************************************	*/

Whatever::Whatever ( void ) : _data(0)
{
	//std::cout << "\033[90mDefault Whatever constructor called\033[0m" << std::endl;
	return ;
}

Whatever::Whatever ( const Whatever &cpy)
{
	//std::cout << "\033[90mCopy Whatever constructor called\033[0m" << std::endl;
	this->_data = cpy._data;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS				*/
/* ****************************************************************************	*/

Whatever	&Whatever::operator=( const Whatever  &rhs )
{
	//std::cout << "\033[90mCopy Whatever operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	this->_data = rhs._data;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR				*/
/* ****************************************************************************	*/

Whatever::~Whatever ( void )
{
	//std::cout << "\033[90mWhatever destructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*									GETERS				*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*									SETERS				*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*								MEMBER FUNCTIONS			*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS				*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const Whatever &obj)
{
	(void)obj;
	out << "This is the overload of '<<' for the Whatever class" << std::endl;
	return out;
}
