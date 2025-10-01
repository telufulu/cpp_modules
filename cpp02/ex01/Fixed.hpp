/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:46:34 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/27 18:01:39 by telufulu         ###   ########.fr       */
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
		// Operators
		Fixed &operator=( const Fixed &rhs );
		// Destructor
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( const int raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;

	private:
		int					_fixedPoint;
		static const int	_fracBits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &obj);
#endif /* FIXED */
