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

int	main ( int argc, char **argv )
{
	std::vector<int> v;
	(void)argc;

	v.push_back(42);
	try
	{
		easyfind(v, static_cast<int>(*argv[1]));
		std::cout << "Finded!" << std::endl;
	} catch (...)
	{
		std::cout << "Not found" << std::endl;
	};
	return 0;
}