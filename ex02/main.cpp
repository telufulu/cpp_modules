/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:46:42 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/28 20:56:51 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main ( void )
{
	Fixed a(42);
	Fixed b(21);
	Fixed const c( 5.05f / 2 );
	Fixed d = ++b;

	if (a >= b && a != b)
		std::cout << "A is different and bigger than B" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << Fixed::min( a, c ) << std::endl;
	std::cout << Fixed::max( a, c ) << std::endl;
	return (0);
}
