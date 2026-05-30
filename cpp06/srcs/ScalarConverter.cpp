#include <iostream>		// cout
#include "ScalarConverter.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/

ScalarConverter::ScalarConverter ( void ) : _data(0)
{
	//std::cout << "\033[90mDefault ScalarConverter constructor called\033[0m" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter ( const ScalarConverter &cpy)
{
	//std::cout << "\033[90mCopy ScalarConverter constructor called\033[0m" << std::endl;
	this->_data = cpy._data;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/

ScalarConverter	&ScalarConverter::operator=( const ScalarConverter  &rhs )
{
	//std::cout << "\033[90mCopy ScalarConverter operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	this->_data = rhs._data;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

ScalarConverter::~ScalarConverter ( void )
{
	//std::cout << "\033[90mScalarConverter destructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*							MEMBER FUNCTIONS									*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const ScalarConverter &obj)
{
	(void)obj;
	out << "This is the overload of '<<' for the ScalarConverter class" << std::endl;
	return out;
}
