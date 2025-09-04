/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:21:54 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/23 20:47:10 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>	// cout, endl
#include <cctype>	// toupper

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	++argv;
	while (argv && *argv)
	{
		while (*argv && **argv)
			std::cout << char(toupper(*(*argv)++));
		++argv;
	}
	std::cout << std::endl;
	return (0);
}
