/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:47:32 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/22 11:47:34 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>				// ostream

template <typename T>
class Array
{
	public:
		// Constructors
		Array( void );
		Array( const unsigned int size );
		Array( Array const &cpy );

		// Arithmetic operators
		Array	&operator=( const Array &rhs );
		T		&operator[](unsigned int index);
		const T	&operator[](unsigned int index) const;

		// Geters
		unsigned int	size(void) const;

		// Destructor
		~Array( void );
	private:
		unsigned int	_size;
		T				*_arr;
};

# include "Array.tpp"

#endif
