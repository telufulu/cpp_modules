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

#include "ScalarConverter.hpp"

int	main ( int argc, char **argv )
{
	if ( argc == 2 && argv )
		//ScalarConverter	a;	// This might throw an error at compiling
		ScalarConverter::convert(argv[1]);
	return 0;
}
