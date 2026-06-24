/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 21:21:30 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/24 21:21:32 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/
template <typename T>
easyfind<T>::easyfind ( void )
{
	//std::cout << "\033[90mDefault easyfind constructor called\033[0m" << std::endl;
	return ;
}

template <typename T>
easyfind<T>::easyfind ( const easyfind &cpy)
{
	//std::cout << "\033[90mCopy easyfind constructor called\033[0m" << std::endl;
	(void)cpy;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/

template <typename T>
easyfind<T>	&easyfind<T>::operator=( const easyfind  &rhs )
{
	//std::cout << "\033[90mCopy easyfind operator called\033[0m" << std::endl;
	(void)rhs;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

template <typename T>
easyfind<T>::~easyfind ( void )
{
	//std::cout << "\033[90measyfind destructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*							MEMBER FUNCTIONS									*/
/* ****************************************************************************	*/

template <typename T>
T::iterator	*easyfind( T &cont, int i )
{
	return std::find()
}