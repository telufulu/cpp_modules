/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 21:36:31 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/26 21:36:32 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>				// ostream

class Span
{
	public:
		// Constructors
		Span( unsigned int size );
		Span( const Span &cpy );

		// Arithmetic operators
		Span &operator=( const Span &rhs );

		// Destructor
		~Span( void );

		// Geters
		unsigned int	getNum( unsigned int pos ) const;
		unsigned int	getSize( void ) const;

		// Member functions
		void			addNumber( unsigned int num );
		unsigned int	shortestSpan( void ) const;
		unsigned int	longestSpan( void ) const;
		void			fillSpan( void );

	private:
		// Constructors
		Span( void );

		unsigned int				_size;
		std::vector<unsigned int>	_span;
};

std::ostream &operator<<(std::ostream &out, const Span &obj);
#endif
