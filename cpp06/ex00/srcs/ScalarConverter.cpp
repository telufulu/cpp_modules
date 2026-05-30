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
void	toChar( const std::string &literal, const double value )
{
	std::cout << "char : ";
	if (literal.empty() || !std::isdigit(literal[0]))
		std::cout << "imposible" << std::endl;
	else if (value < 32 || value > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void	ScalarConverter::convert( const std::string &literal )
{
	char	*end;
	double	value;

	value = std::strtod(literal.c_str(), &end);
	toChar(literal, value);
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
