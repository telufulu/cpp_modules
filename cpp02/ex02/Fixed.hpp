/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:46:34 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/28 20:56:09 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>	// cout
# include <cmath>		// roundf

class Fixed
{
	public:
		// Constructors
		Fixed( void );				// default
		Fixed( const Fixed &cpy);	// copy
		Fixed( const int &c);		// conversion
		Fixed( const float &c);		// conversion
		// Arithmetic operators +, -, *, and /.
		Fixed &operator=( const Fixed &rhs );
		Fixed operator+( const Fixed &rhs );
		Fixed operator-( const Fixed &rhs );
		Fixed operator*( const Fixed &rhs );
		Fixed operator/( const Fixed &rhs );
		// Comparision operators
		bool	operator>( const Fixed &rhs );
		bool	operator<( const Fixed &rhs );
		bool	operator>=( const Fixed &rhs );
		bool	operator<=( const Fixed &rhs );
		bool	operator==( const Fixed &rhs );
		bool	operator!=( const Fixed &rhs );
		// Increment and decrement operators
		Fixed	&operator++( void );
		Fixed	operator++( int );
		Fixed	&operator--( void );
		Fixed	operator--( int );
		// Destructor
		~Fixed( void );

		// Member functions
		int					getRawBits( void ) const;
		void				setRawBits( const int raw );
		int					toInt( void ) const;
		float				toFloat( void ) const;
		static Fixed		&min( Fixed &a, Fixed &b);
		static const Fixed	&min( const Fixed &a, const Fixed &b);
		static Fixed		&max( Fixed &a, Fixed &b);
		static const Fixed	&max( const Fixed &a, const Fixed &b);
	private:
		int					_fixedPoint;
		static const int	_fracBits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &obj);
#endif /* FIXED */
