#include "BitcoinExchange.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/

BitcoinExchange::BitcoinExchange ( void ) : _data(0)
{
	//std::cout << "\033[90mDefault BitcoinExchange constructor called\033[0m" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange ( const BitcoinExchange &cpy)
{
	//std::cout << "\033[90mCopy BitcoinExchange constructor called\033[0m" << std::endl;
	this->_data = cpy._data;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange  &rhs )
{
	//std::cout << "\033[90mCopy BitcoinExchange operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	this->_data = rhs._data;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

BitcoinExchange::~BitcoinExchange ( void )
{
	//std::cout << "\033[90mBitcoinExchange destructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*							MEMBER FUNCTIONS									*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const BitcoinExchange &obj)
{
	out << "This is the overload of '<<' for the BitcoinExchange class" << std::endl;
	return out;
}
