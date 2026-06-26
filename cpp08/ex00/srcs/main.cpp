/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 21:21:43 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/24 21:21:44 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <limits>
#include <cstdlib>		// atoi


int	main ( int argc, char **argv )
{
	std::vector<int>	v;
	long				n;

	v.push_back(42);
	v.push_back(21);
	v.push_back(16);
	v.push_back(-1);
	v.push_back(+5);
	v.push_back(std::numeric_limits<int>::min());
	v.push_back(std::numeric_limits<int>::max());
	if (argc == 1)
	{
		std::cout << "Not enough arguments."
		<< " Usage: ./easyfind <number>" << std::endl;
		return 1;
	}
	n = std::atol(argv[1]);
	if (n > std::numeric_limits<int>::max()
		|| n < std::numeric_limits<int>::min())
	{
		std::cout << "Number out of int limits" << std::endl;
		return 1;
	}
	try
	{
		std::cout << "TEST 1: std::vector" << std::endl; 
		::easyfind(v, std::atoi(argv[1]));
		std::cout << "Finded!" << std::endl;
	} catch (...)
	{
		std::cout << "Not found" << std::endl;
	};
	//std::cout << std::endl;
	return 0;
}