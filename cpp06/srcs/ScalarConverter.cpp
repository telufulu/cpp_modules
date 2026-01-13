/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:24:06 by telufulu          #+#    #+#             */
/*   Updated: 2026/01/13 21:49:56 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <cstdlib>
#include <limits>

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
	char	*end;

	try {
		std::cout << "char: ";
		ScalarConverter::_parseChar(std::strtol(literal, &end, 10));
	} catch (ScalarConverter::NonDisplayableException &e){
		std::cout << e.what() << std::endl;
	} catch (ScalarConverter::ImpossibleException &e){
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "int: ";
		long res = std::strtol(literal, &end, 10);
		ScalarConverter::_parseInt(res);
	} catch (ScalarConverter::NonDisplayableException &e){
		std::cout << e.what() << std::endl;
	} catch (ScalarConverter::ImpossibleException &e){
		std::cout << e.what() << std::endl;
	}
}

/* ************************************************************************* */
/*							HELPER FUNCTIONS								 */
/* ************************************************************************* */
void	ScalarConverter::_parseChar(long literal)
{
	if (literal < std::numeric_limits<char>::min() || 
			literal > std::numeric_limits<char>::max())
		throw ScalarConverter::ImpossibleException();
	if (literal < 32 || literal > 126)
		throw ScalarConverter::NonDisplayableException();
	std::cout << (char)literal << std::endl;
}

void	ScalarConverter::_parseInt(long literal)
{
	if (literal < std::numeric_limits<int>::min() || 
			literal > std::numeric_limits<int>::max())
		throw ScalarConverter::ImpossibleException();
	std::cout << literal << std::endl;
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
