/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 21:36:37 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/26 21:36:38 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// cout
#include <stdexcept>	// std::exception
#include "Span.hpp"

int	main ( int argc, char **argv )
{
	unsigned long	def_size = 42;

	if (argc == 1)
		return 1;
	if (argc == 2)
		def_size = std::atol(argv[1]);
	if (def_size > std::numeric_limits<unsigned int>::max())
	{
		std::cout << "\033[31mError:\033[0m that number is too big" << std::endl;
		return 1;
	}
	
	Span	a(def_size);
	try
	{
		std::cout << "TEST 1" << std::endl;
		a.fillSpan();
		std::cout << a << std::endl;
	} catch ( const std::exception &e )
	{
		std::cout << std::endl << "\033[31mError: \033[0m" << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "TEST 2" << std::endl;
		Span	b(def_size);

		b.addNumber(34);
		b.addNumber(12);
		b.addNumber(100);
		b.addNumber(1993);
		b.addNumber(2000);
		std::cout << "Shortest distance of b: " << b.shortestSpan() << std::endl;
		std::cout << "Longest distance of b: " << b.longestSpan() << std::endl;
	} catch ( const std::exception &e )
	{
		std::cout << "\033[31mError: \033[0m" << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "TEST 3" << std::endl;
		Span	c(def_size);

		c.addNumber(34);
		c.shortestSpan();
	} catch ( const std::exception &e )
	{
		std::cout << "\033[31mError: \033[0m" << e.what() << std::endl;
	}
	return 0;
}
