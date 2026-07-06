/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:01:28 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/05 19:42:24 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>	// cout

int	main ( int argc, const char **argv  )
{
	if ( argc != 2 )
	{
		std::cout << "Try some of this commands:" << std::endl;
		std::cout << "./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl
			<< "./RPN \"7 7 * 7 -\"" << std::endl
			<< "./RPN \"1 2 * 2 / 2 * 2 4 - +\"" << std::endl
			<< "./RPN \"(1 + 1)\"" << std::endl;
		return 1;
	}

	try {
		RPN	stack(argv[1]);
		std::string	s = stack.getStringStack();
		int	solve = stack.solve();

		std::cout << s << " = " << solve << std::endl;
	} catch (...) {
		std::cout << "\033[31mError\033[0m" << std::endl; 
	}
	return 0;
}
