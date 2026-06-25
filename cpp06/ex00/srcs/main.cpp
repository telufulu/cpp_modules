/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:23:51 by telufulu          #+#    #+#             */
/*   Updated: 2026/01/13 21:28:43 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Output example
// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0

// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan

// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0

#include "ScalarConverter.hpp"
#include <iomanip>				// string

#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int	main ( int argc, char **argv )
{
	// TEST 1
	//   char : '~'
	//   int : 126
	//   float : 127f
	//   double : 127
	std::cout << "TEST 1 (126.9999)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("126.9999");
	std::cout << std::endl;

	// TEST 2
	//   char : Non displayable
	//   int : 0
	//   float : 0.0f
	//   double : 0.0
	std::cout << "TEST 2 (0)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;

	// TEST 3
	//   char : 'A'
	//   int : 65
	//   float : 65.0f
	//   double : 65.0
	std::cout << "TEST 3 (65)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("65");

	std::cout << std::endl;

	// TEST 4
	//   char : ' '
	//   int : 32
	//   float : 32.0f
	//   double : 32.0
	std::cout << "TEST 4 (32)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("32");

	std::cout << std::endl;

	// TEST 5
	//   char : Non displayable
	//   int : 127
	//   float : 127.0f
	//   double : 127.0
	std::cout << "TEST 5 (127)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("127");
	std::cout << std::endl;

	// TEST 6
	//   char : impossible
	//   int : impossible
	//   float : 2.14748e+09f
	//   double : 2.14748e+09
	std::cout << "TEST 6 (2147483648)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << std::endl;

	// TEST 7
	//   char : '*'
	//   int : 42
	//   float : 42.0f
	//   double : 42.0
	std::cout << "TEST 7 (42.0f)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;

	// TEST 8
	//   char : '*'
	//   int : 42
	//   float : 42.0f
	//   double : 42.0
	std::cout << "TEST 8 (42abc)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("42abc");
	std::cout << std::endl;

	// TEST 9
	//   char : 'c'
	//   int : 99
	//   float : 99.0f
	//   double : 99.0
	std::cout << "TEST 9 (c)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("c");
	std::cout << std::endl;

	// TEST 10
	//   char : impossible
	//   int : impossible
	//   float : nanf
	//   double : nan
	std::cout << "TEST 10 (nan)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;

	// TEST 11
	//   char : impossible
	//   int : impossible
	//   float : nanf
	//   double : nan
	std::cout << "TEST 11 (nanf)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;

	// TEST 12
	//   char : impossible
	//   int : impossible
	//   float : +inff
	//   double : +inf
	std::cout << "TEST 12 (+inff)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;

	// TEST 13
	//   char : impossible
	//   int : impossible
	//   float : -inff
	//   double : -inf
	std::cout << "TEST 13 (-inff)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;

	// TEST 14
	//   char : impossible
	//   int : impossible
	//   float : -inff
	//   double : -1e+40
	std::cout << "TEST 14 (-1e40)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("-1e40");
	std::cout << std::endl;

	// TEST 15
	//   char : impossible
	//   int : impossible
	//   float : impossible
	//   double : impossible
	std::cout << "TEST 15 (empty)" << std::endl
		<< std::string(14, '=') << std::endl;
	ScalarConverter::convert("");
	std::cout << std::endl;

	// SUBJECT TEST
	if (argc == 2)
	{
		std::cout << "SUBJECT TEST" << std::endl
			<< std::string(14, '=') << std::endl;
		ScalarConverter::convert(argv[1]);
	}
	return 0;
}
