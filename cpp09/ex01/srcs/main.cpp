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

/*
===============================================================================
							RPN TEST BATTERY
===============================================================================
Subject examples
-------------------------------------------------------------------------------
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
Expected: 42

./RPN "7 7 * 7 -"
Expected: 42

./RPN "1 2 * 2 / 2 * 2 4 - +"
Expected: 0

./RPN "(1 + 1)"
Expected: Error

Basic valid operations
-------------------------------------------------------------------------------
./RPN "1 2 +"
Expected: 3

./RPN "8 3 -"
Expected: 5

./RPN "4 5 *"
Expected: 20

./RPN "8 2 /"
Expected: 4

Operand order checks
-------------------------------------------------------------------------------
./RPN "5 3 -"
Expected: 2

./RPN "3 5 -"
Expected: -2

./RPN "8 2 /"
Expected: 4

./RPN "2 8 /"
Expected: 0

Negative results
-------------------------------------------------------------------------------
./RPN "5 3 4 + -"
Expected: -2

./RPN "1 9 -"
Expected: -8

./RPN "1 9 - 2 *"
Expected: -16

./RPN "1 9 - 2 /"
Expected: -4

Integer division
-------------------------------------------------------------------------------
./RPN "7 2 /"
Expected: 3

./RPN "9 4 /"
Expected: 2

./RPN "5 2 /"
Expected: 2

./RPN "1 2 /"
Expected: 0

Zero as a valid operand
-------------------------------------------------------------------------------
./RPN "0"
Expected: 0

./RPN "0 1 +"
Expected: 1

./RPN "9 0 *"
Expected: 0

./RPN "0 9 -"
Expected: -9

Division by zero
-------------------------------------------------------------------------------
./RPN "4 0 /"
Expected: Error

./RPN "0 0 /"
Expected: Error

./RPN "8 2 2 - /"
Expected: Error

Long valid expressions
-------------------------------------------------------------------------------
./RPN "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 +"
Expected: 45

./RPN "9 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 +"
Expected: 45

./RPN "2 3 + 4 * 5 -"
Expected: 15

./RPN "9 1 - 2 / 3 *"
Expected: 12

Large results
-------------------------------------------------------------------------------
./RPN "9 9 *"
Expected: 81

./RPN "9 9 * 9 *"
Expected: 729

./RPN "9 9 * 9 * 9 *"
Expected: 6561

./RPN "9 9 * 9 9 * +"
Expected: 162

Invalid tokens
-------------------------------------------------------------------------------
./RPN "1 2 &"
Expected: Error

./RPN "1 2 ^"
Expected: Error

./RPN "1 2 %"
Expected: Error

./RPN "a b +"
Expected: Error

./RPN "1 2 ++"
Expected: Error

Numbers with more than one digit
-------------------------------------------------------------------------------
./RPN "10"
Expected: Error

./RPN "12 3 +"
Expected: Error

./RPN "1 23 +"
Expected: Error

./RPN "99 1 +"
Expected: Error

Decimals, signed input numbers and unsupported formats
-------------------------------------------------------------------------------
./RPN "1.5 2 +"
Expected: Error

./RPN "-1 2 +"
Expected: Error

./RPN "+1 2 +"
Expected: Error

./RPN "1f 2 +"
Expected: Error

Missing operands
-------------------------------------------------------------------------------
./RPN "+"
Expected: Error

./RPN "-"
Expected: Error

./RPN "*"
Expected: Error

./RPN "/"
Expected: Error

./RPN "1 +"
Expected: Error

./RPN "1 2 + +"
Expected: Error

Extra operands
-------------------------------------------------------------------------------
./RPN "1 2"
Expected: Error

./RPN "1 2 3"
Expected: Error

./RPN "1 2 + 3"
Expected: Error

./RPN "5 3 4 +"
Expected: Error

Empty or whitespace-only expressions
-------------------------------------------------------------------------------
./RPN ""
Expected: Error

./RPN " "
Expected: Error

./RPN "      "
Expected: Error

Whitespace handling
-------------------------------------------------------------------------------
./RPN "   1 2 +   "
Expected: 3

./RPN "1    2      +"
Expected: 3

./RPN $'1\t2\t+'
Expected: 3

Stack order checks
-------------------------------------------------------------------------------
./RPN "5 3 4 + -"
Expected: -2

./RPN "2 3 4 * +"
Expected: 14

./RPN "2 3 + 4 *"
Expected: 20

Int vs char storage checks
-------------------------------------------------------------------------------
./RPN "5"
Expected: 5

./RPN "5 1 +"
Expected: 6

./RPN "9 1 -"
Expected: 8

Program argument checks
-------------------------------------------------------------------------------
./RPN
Expected: Error

./RPN "1 2 +" "3 4 +"
Expected: Error

./RPN 1 2 +
Expected: Error
*/