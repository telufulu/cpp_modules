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

int	main ( int argc, char **argv )
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	return 0;
}
