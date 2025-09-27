/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:46:34 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/27 16:54:17 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>	// cout

class Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed &cpy);
		Fixed &operator=( const Fixed &rhs );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( const int raw );
	
	private:
		int	_fixedPoint;
};
#endif
