/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:01:28 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/08 20:49:39 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>	// cout

int	main ( int argc, const char **argv  )
{
	if ( argc != 2 || !argv)
	{
		return 1;
	}

	BitcoinExchange	data(argv[1]);
	return 0;
}
