/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:54:10 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/28 14:54:46 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main( int argc, char **argv )
{
	try
	{
		PmergeMe	p(argc, argv);

		p.solveVector();
		p.solveDeque();
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[0mError:\033[0m " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
