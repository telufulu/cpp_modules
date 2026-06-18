/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:47:46 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/18 12:47:48 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// cout
#include "Serializer.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/
Serializer::Serializer ( void )
{
	//std::cout << "\033[90mDefault Serializer constructor called\033[0m" << std::endl;
	return ;
}

Serializer::Serializer ( const Serializer &cpy)
{
	//std::cout << "\033[90mCopy Serializer constructor called\033[0m" << std::endl;
	(void)cpy;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/

Serializer	&Serializer::operator=( const Serializer  &rhs )
{
	//std::cout << "\033[90mCopy Serializer operator called\033[0m" << std::endl;
	(void)rhs;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

Serializer::~Serializer ( void )
{
	//std::cout << "\033[90mSerializer destructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*								MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
uintptr_t	Serializer::serialize( Data* ptr )
{
	// It takes a pointer and converts it to the unsigned integer type uintptr_t.
	return reinterpret_cast<uintptr_t>(ptr);
}

Data			*Serializer::deserialize(uintptr_t raw)
{
	// It takes an unsigned integer parameter and converts it to a pointer to Data.
	return reinterpret_cast<Data *>(raw);
}
/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const Serializer &obj)
{
	(void)obj;
	out << "This is the overload of '<<' for the Serializer class" << std::endl;
	return out;
}
