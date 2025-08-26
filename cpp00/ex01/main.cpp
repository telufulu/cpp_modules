/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:11 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/26 15:38:34 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main( void )
{
	PhoneBook	pb;
	std::string	input;

	while (1)
	{
		std::cin >> input;
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else
			std::cout << "I'm alive!" << std::endl;
	}
	return (0);
}
