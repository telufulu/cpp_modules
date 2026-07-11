/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 20:38:06 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/11 15:24:35 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <exceptions>

/* ****************************************************************************	*/
/*								AUXILIAR FUNTIONS								*/
/* ****************************************************************************	*/
std::string	BitcoinExchange::_getDate( const std::string &line, char sep ) const
{
	std::string	date;

	sep = line.find(',');
	if (sep == std::string::npos)
		throw std::runtime_error("wrong format file");
	date = line.substr(0, sep);
	if (!this->isValidDate(date))
		throw std::runtime_error("invalid date");
	return (date);
}

double	BitcoinExchange::_getValue( const std::string &line, char sep ) const
{
	std::string	valueStr;
	double		value;

	valueStr = line.substr(sep + 1);
	if (!this->isValidValue(valueStr, value))
		throw std::runtime_error("invalid value");

	return (value);
}

bool	BitcoinExchange::_isValidValue(const std::string &valueStr, double &value) const
{
	char*	end;

	if (valueStr.empty())
		return (false);

	errno = 0;
	value = std::strtod(valueStr.c_str(), &end);

	if (*end != '\0')
		return (false);
	if (errno == ERANGE)
		return (false);
	if (value < 0)
		return (false);

	return (true);
}

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/
BitcoinExchange::BitcoinExchange ( void )
{
	//std::cout << "\033[90mVoid BitcoinExchange constructor called\033[0m" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange ( const char *file_path )
{
	//std::cout << "\033[90mDefault BitcoinExchange constructor called\033[0m" << std::endl;
	std::ifstream	file(file_path);
	std::string		line;
	std::string		date;
	std::string		rateStr;
	char			sep;
	double			rate;
	char*			end;

	if (!file.is_open())
		throw std::runtime_error("could not open database.");
	if (!std::getline(file, line))
		throw std::runtime_error("empty database.");
	if (line != "date | value" && line != "date,value")
		throw std::runtime_error("wrong format file");
	while (std::getline(file, line))
	{
		try
		{
			date = this->getDate(line, sep);
			rate = this->getValue(line, sep);
			this->_rates[date] = rate;
		}
		catch (const std::exception& e) { continue ; }
	}
	if (this->_rates.empty())
		throw std::runtime_error("empty database.");	
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
