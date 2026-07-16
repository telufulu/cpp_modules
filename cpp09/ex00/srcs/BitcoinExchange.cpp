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

#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include <cerrno>
#include <cctype>

/* ************************************************************************** */
/*                              AUXILIAR FUNCTIONS                            */
/* ************************************************************************** */

bool	BitcoinExchange::_isValidDate( const std::string &date ) const
{
	int	year;
	int	month;
	int	day;

	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (year < 0)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	return true;
}

std::string	BitcoinExchange::_getDate( const std::string &line, size_t sep ) const
{
	std::string	date;

	date = line.substr(0, sep - 1);
	if (!this->_isValidDate(date))
		throw std::runtime_error("bad input => " + line);
	return date;
}

bool	BitcoinExchange::_isValidValue( const std::string &valueStr, double &value ) const
{
	char	*end;

	if (valueStr.empty())
		return false;
	errno = 0;
	value = std::strtod(valueStr.c_str(), &end);
	if (*end != '\0')
		return false;
	if (errno == ERANGE)
		return false;
	if (value < 0)
		return false;
	return true;
}

double	BitcoinExchange::_getValue( const std::string &line, size_t sep ) const
{
	double		value;
	std::string	valueStr;

	valueStr = line.substr(sep + 2);
	if (!this->_isValidValue(valueStr, value))
		throw std::runtime_error("not a positive number.");
	if (value > 1000)
		throw std::runtime_error("too large a number.");
	return value;
}

double	BitcoinExchange::_getRateForDate( const std::string &date ) const
{
	std::map<std::string, double>::const_iterator	it;

	it = this->_db.upper_bound(date);
	if (it == this->_db.begin())
		throw std::runtime_error("bad input => " + date);
	--it;
	return it->second;
}

/* ************************************************************************** */
/*                              CONSTRUCTORS                                  */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange( void )
{
	return ;
}

BitcoinExchange::BitcoinExchange( const char *file_path )
{
	std::ifstream	file(file_path);
	std::string		line;
	std::string		date;
	double			rate;
	size_t			sep;

	if (!file.is_open())
		throw std::runtime_error("could not open database.");
	if (!std::getline(file, line))
		throw std::runtime_error("empty database.");
	if (line != "date,exchange_rate")
		throw std::runtime_error("wrong format file");
	while (std::getline(file, line))
	{
		try
		{
			sep = line.find(',');
			if (sep == std::string::npos)
				throw std::runtime_error("wrong format file");
			date = line.substr(0, sep);
			if (!this->_isValidDate(date))
				throw std::runtime_error("invalid date");
			if (!this->_isValidValue(line.substr(sep + 1), rate))
				throw std::runtime_error("invalid value");
			this->_db[date] = rate;
		}
		catch (const std::exception &e)
		{
			continue ;
		}
	}
	if (this->_db.empty())
		throw std::runtime_error("empty database.");
	return ;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &cpy )
{
	if (this == &cpy)
		return ;
	this->_db = cpy._db;
	return ;
}

/* ************************************************************************** */
/*                              OPERATORS                                     */
/* ************************************************************************** */

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange &rhs )
{
	if (this == &rhs)
		return *this;
	this->_db = rhs._db;
	return *this;
}

/* ************************************************************************** */
/*                              DESTRUCTOR                                    */
/* ************************************************************************** */

BitcoinExchange::~BitcoinExchange( void )
{
	return ;
}

/* ************************************************************************** */
/*                              MEMBER FUNCTIONS                              */
/* ************************************************************************** */

void	BitcoinExchange::processInput( const char *file_path ) const
{
	std::ifstream	file(file_path);
	std::string		line;
	std::string		date;
	double			value;
	double			rate;
	size_t			sep;

	if (!file.is_open())
		throw std::runtime_error("could not open file.");
	if (!std::getline(file, line))
		throw std::runtime_error("empty file.");
	if (line != "date | value")
		throw std::runtime_error("wrong input format.");
	while (std::getline(file, line))
	{
		try
		{
			sep = line.find('|');
			if (sep == std::string::npos)
				throw std::runtime_error("bad input => " + line);
			date = this->_getDate(line, sep);
			value = this->_getValue(line, sep);
			rate = this->_getRateForDate(date);
			std::cout << date << " => " << value << " = "
				<< value * rate << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "\033[31mError:\033[0m " << e.what() << std::endl;
		}
	}
}

/* ************************************************************************** */
/*                          NON MEMBER FUNCTIONS                              */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &out, const BitcoinExchange &obj )
{
	(void)obj;
	out << "BitcoinExchange database loaded";
	return out;
}