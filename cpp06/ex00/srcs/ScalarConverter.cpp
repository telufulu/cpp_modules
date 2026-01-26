/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:24:06 by telufulu          #+#    #+#             */
/*   Updated: 2026/01/26 20:29:43 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>

/* ************************************************************************* */
/*								CONSTRUCTORS								 */
/* ************************************************************************* */

ScalarConverter::ScalarConverter ( void )
{
	std::cout << "\033[90mDefault ScalarConverter constructor called\033[0m" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter ( const ScalarConverter &cpy)
{
	//std::cout << "\033[90mCopy ScalarConverter constructor called\033[0m" << std::endl;
	(void)cpy;
	return ;
}

/* ************************************************************************	*/
/*								OPERATORS									*/
/* ************************************************************************	*/

ScalarConverter	&ScalarConverter::operator=( const ScalarConverter  &rhs )
{
	//std::cout << "\033[90mCopy ScalarConverter operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

/* ************************************************************************	*/
/*								DESTRUCTOR									*/
/* ************************************************************************	*/

ScalarConverter::~ScalarConverter ( void )
{
	std::cout << "\033[90mScalarConverter destructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************	*/
/*							STATIC METHODS									*/
/* ************************************************************************ */
void	ScalarConverter::convert( const char *literal )
{
	try {
		std::cout << "char: ";
		ScalarConverter::_parseChar(literal);
	} catch (const std::exception &e) { 
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "int: ";
		ScalarConverter::_parseInt(literal);
	} catch (const std::exception &e) { 
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "float: ";
		ScalarConverter::_parseFloat(literal);
	} catch (const std::exception &e) { 
		std::cout << e.what() << std::endl;
	}
}

/* ************************************************************************* */
/*							HELPER FUNCTIONS								 */
/* ************************************************************************* */
void	ScalarConverter::_parseChar(const char *literal)
{
	long	lit;
	char	*end;

	lit = std::strtol(literal, &end, 10);
	if (!lit && !isdigit(static_cast<unsigned char>(*literal)))
		lit = *literal;
	if (lit < std::numeric_limits<char>::min() || 
			lit > std::numeric_limits<char>::max())
		throw ScalarConverter::ImpossibleException();
	if (lit < 32 || lit > 126)
		throw ScalarConverter::NonDisplayableException();
	std::cout << (char)lit << std::endl;
}

void	ScalarConverter::_parseInt(const char *literal)
{
	char	*end;
	long	lit;
	
	lit = std::strtol(literal, &end, 10);
	if (lit < std::numeric_limits<int>::min() || 
			lit > std::numeric_limits<int>::max())
		throw ScalarConverter::ImpossibleException();
	std::cout << lit << std::endl;
}

void	ScalarConverter::_parseFloat(const char *literal)
{
	long double	lit;
	char	*end;

	lit = strtod(literal, &end);
	if (lit < std::numeric_limits<double>::min() || 
			lit > std::numeric_limits<double>::max())
		throw ScalarConverter::ImpossibleException();
	std::cout << lit << std::endl;
}

/* ************************************************************************* */
/*							EXCEPTION CLASSES								 */
/* ************************************************************************* */
const char	*ScalarConverter::ImpossibleException::what() const throw()
{
	return "impossible";
}

const char	*ScalarConverter::NonDisplayableException::what() const throw()
{
	return "Non displayable";
}

/* ************************************************************************* */
/*							NON MEMBER FUNCTIONS							 */
/* ************************************************************************* */
std::ostream	&operator<<(std::ostream &out, const ScalarConverter &obj)
{
	(void)obj;
	out << "This is the overload of '<<' for the ScalarConverter class" << std::endl;
	return out;
}
