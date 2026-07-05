/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:01:28 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/05 18:58:15 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>	// cout

int	main ( int argc, const char **argv  )
{
	if ( argc != 2 )
		return 1;

	try {
		RPN	res(argv[1]);

		std::cout << res << " = ";
		//std::cout << res.solve() << std::endl;
	} catch (...) {
		std::cout << "\033[31mError\033[0m" << std::endl; 
	}
	return 0;
}
