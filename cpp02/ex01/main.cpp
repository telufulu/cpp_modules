/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:46:42 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/27 18:10:30 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main ( void )
{
	Fixed a;
	const Fixed b( 10 );
	const Fixed c( 42.42f );
	const Fixed d( b );

	a = Fixed( 1234.4321f );
	std::cout << "[ A ]" << std::endl;
	std::cout << "Raw bits: " << a.getRawBits() << std::endl;
	std::cout << "Float is " << a << std::endl;
	std::cout << "Int is " << a.toInt() << std::endl;
	std::cout << "[ B ]" << std::endl;
	std::cout << "Raw bits: " << b.getRawBits() << std::endl;
	std::cout << "Float is " << b << std::endl;
	std::cout << "Int is " << b.toInt() << std::endl;
	std::cout << "[ C ]" << std::endl;
	std::cout << "Raw bits: " << c.getRawBits() << std::endl;
	std::cout << "Float is " << c << std::endl;
	std::cout << "Int is " << c.toInt() << std::endl;
	return (0);
}
