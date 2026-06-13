/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 22:55:19 by telufulu          #+#    #+#             */
/*   Updated: 2026/05/30 22:55:21 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// cout
#include <cstdlib>		// strtod
#include <climits>		// INT_MIN, INT_MAX
#include <cmath>		// floor, isinf, isnan
#include <limits>		// numeric_limits
#include "ScalarConverter.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/

ScalarConverter::ScalarConverter ( void )
{
	//std::cout << "\033[90mDefault ScalarConverter constructor called\033[0m" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter ( const ScalarConverter &cpy)
{
	//std::cout << "\033[90mCopy ScalarConverter constructor called\033[0m" << std::endl;
	(void)cpy;
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
/*								MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
void	toChar( const std::string &literal, const double value, char *end )
{
	// std::cout << "(" << static_cast<char>(value) << ") ";
	std::cout << "char : ";
	if (literal.empty()
		|| std::isnan(value) || std::isinf(value)
		|| (literal.c_str() == end && literal.size() > 1)
		|| value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if ((literal.size() > 1 || std::isdigit(static_cast<unsigned char>(literal[0])))
		&& (!(value > 31) || !(value < 127)))
		std::cout << "non displayable" << std::endl;
	else if (literal.size() > 1)
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "'" << literal << "'" << std::endl;
}

void	toInt( const std::string &literal, const double value )
{
	// std::cout << "(" << static_cast<int>(value) << ") ";
	std::cout << "int : ";
	if (literal.empty()
		|| (literal.length() > 1
			&& !std::isdigit(static_cast<unsigned char>(literal[0]))
			&& ((literal[0] != '-' && literal[0] != '+')
				|| !std::isdigit(static_cast<unsigned char>(literal[1]))))
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

// NANF EXAMPLES
// 0.0f / 0.0f    -> indeterminate form
// sqrtf(-1.0f)   -> no real square root
// inff - inff    -> indeterminate form
// logf(-2.0f)    -> outside the domain

// INFF/-INFF EXAMPLES
// Cases that produce +inff:
//   1.0f / 0.0f         -> division of a finite non-zero by zero
//   1e38f * 10.0f       -> overflow (result too large for float)
//   expf(1000.0f)       -> overflow

// Cases that produce -inff:
//   -1.0f / 0.0f        -> division of a negative finite by zero
//   logf(0.0f)          -> limit tends to -inff
//   -1e38f * 10.0f      -> negative overflow
void	toFloat( const std::string &literal, const double value )
{
	// std::cout << "(" << static_cast<float>(value) << ") ";
	std::cout << "float : ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value) && value < 0)
		std::cout << "-inff" << std::endl;
	else if (std::isinf(value))
		std::cout << "+inff" << std::endl;
	else if (literal.empty()
		|| (literal.length() > 1
			&& !std::isdigit(static_cast<unsigned char>(literal[0]))
			&& ((literal[0] != '-' && literal[0] != '+')
				|| !std::isdigit(static_cast<unsigned char>(literal[1])))))
		std::cout << "impossible" << std::endl;
	else
	{
		std::cout << static_cast<float>(value);
		if (std::floor(value) == value && std::fabs(value) < 1000000.0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	return ;
}
// NAN EXAMPLES
// 0.0 / 0.0    -> indeterminate form
// sqrt(-1.0)   -> no real square root
// inf - inf    -> indeterminate form
// log(-2.0)    -> outside the domain

// INF/-INF EXAMPLES
// Cases that produce +inf:
//   1.0 / 0.0           -> division of a finite non-zero by zero
//   1e308 * 10.0        -> overflow (result too large for double)
//   exp(1000.0)         -> overflow

// Cases that produce -inf:
//   -1.0 / 0.0          -> division of a negative finite by zero
//   log(0.0)            -> limit tends to -inf
//   -1e308 * 10.0       -> negative overflow
void	toDouble( const std::string &literal, const double value )
{
	// std::cout << "(" << static_cast<double>(value) << ") ";
	std::cout << "double : ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value) && value < 0)
		std::cout << "-inf" << std::endl;
	else if (std::isinf(value))
		std::cout << "+inf" << std::endl;
	else if (literal.empty()
		|| (literal.length() > 1
			&& !std::isdigit(static_cast<unsigned char>(literal[0]))
			&& ((literal[0] != '-' && literal[0] != '+')
				|| !std::isdigit(static_cast<unsigned char>(literal[1])))))
		std::cout << "impossible" << std::endl;
	else
	{
		std::cout << value;
		if (std::floor(value) == value && std::fabs(value) < 1000000.0)
			std::cout << ".0";
		std::cout << std::endl;
	}
	return ;
}

void	ScalarConverter::convert( const std::string &literal )
{
	char	*end = NULL;
	double	value;

	if (literal.length() == 1
		&& !std::isdigit(static_cast<unsigned char>(literal[0])))
		value = static_cast<double>(literal[0]);
	else
		value = std::strtod(literal.c_str(), &end);
	toChar(literal, value, end);
	toInt(literal, value);
	toFloat(literal, value);
	toDouble(literal, value);
}

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const ScalarConverter &obj)
{
	(void)obj;
	out << "This is the overload of '<<' for the ScalarConverter class" << std::endl;
	return out;
}
