/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:24:06 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/19 11:24:08 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/

ScalarConverter::ScalarConverter ( void )
{
	std::cout << "\033[90mDefault ScalarConverter constructor called\033[0m" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter ( const ScalarConverter &cpy)
{
	//std::cout << "\033[90mCopy ScalarConverter constructor called\033[0m" << std::endl;
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
	std::cout << "\033[90mScalarConverter destructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*							STATIC METHODS									*/
/* ****************************************************************************	*/
static void	ScalarConverter::convert( const char *literal )
{
	int	index = 0;
	int	type[] = {std::isdigit(*literal)};

	switch (index < 1)
	{
		case 0:
			std::cout << literal[0] << std::endl;
		case 1:
			std::coud << "other class" << std::endl;
	}
}

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const ScalarConverter &obj)
{
	out << "This is the overload of '<<' for the ScalarConverter class" << std::endl;
	return out;
}
