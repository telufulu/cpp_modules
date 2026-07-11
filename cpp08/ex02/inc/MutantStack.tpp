/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:50:06 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/27 17:50:07 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>			// cout
#include "MutantStack.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/
template <typename T>
MutantStack<T>::MutantStack ( void )
{
	//std::cout << "\033[90mDefault MutantStack constructor called\033[0m" << std::endl;
	return ;
}

template <typename T>
MutantStack<T>::MutantStack ( const MutantStack &cpy)
{
	//std::cout << "\033[90mCopy MutantStack constructor called\033[0m" << std::endl;
	if (this == &cpy)
		return ;
	this = std::stack<T>(cpy);
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/
template <typename T>
MutantStack<T>	&MutantStack<T>::operator=( const MutantStack  &rhs )
{
	//std::cout << "\033[90mCopy MutantStack operator called\033[0m" << std::endl;
	if (this == &rhs)
		return (*this);
	std::stack<T>::operator=(rhs);
	return (*this);
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/
template <typename T>
MutantStack<T>::~MutantStack ( void )
{
	//std::cout << "\033[90mMutantStack destructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*									GETERS										*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*									SETERS										*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*								MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void )
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void )
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin( void ) const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end( void ) const
{
	return this->c.end();
}
/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
template <typename T>
std::ostream	&operator<<(std::ostream &out, const MutantStack<T> &obj)
{
	(void)obj;
	out << "This is the overload of '<<' for the MutantStack class" << std::endl;
	return out;
}
