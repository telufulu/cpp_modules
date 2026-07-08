/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 20:38:06 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/08 21:28:58 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <exceptions>

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/

BitcoinExchange::BitcoinExchange ( void )
{
	//std::cout << "\033[90mVoid BitcoinExchange constructor called\033[0m" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange ( const char *file )
{
	//std::cout << "\033[90mDefault BitcoinExchange constructor called\033[0m" << std::endl;
	std::ifstream	file(file);

	if (!file.is_open())
		throw std::runtime_error("Unable to open file");
	
	return ;
}

BitcoinExchange::BitcoinExchange ( const BitcoinExchange &cpy)
{
	//std::cout << "\033[90mCopy BitcoinExchange constructor called\033[0m" << std::endl;
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
