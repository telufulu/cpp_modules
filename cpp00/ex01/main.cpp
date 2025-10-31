/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:11 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/04 17:06:20 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	menu( void )
{
	std::string	divider(52, '-');

	std::cout << "\033[2J\033[1;1H";	
	std::cout << divider << std::endl;
	std::cout << "|              *MY AWESOME PHONEBOOK*              |\n";
	std::cout << divider << std::endl;
	std::cout << "Type and order:\n";
	std::cout << "\t-ADD:\t add a new contact\n";
	std::cout << "\t-SEARCH: display all contacts\n";
	std::cout << "\t-EXIT:\t exit phonebook\n";
}

int	main( void )
{
	PhoneBook	pb;
	std::string	input;

	while (1)
	{
		menu();
		std::getline(std::cin, input);
		if (input == "EXIT")
		{
			std::cout << "PhoneBook deleted. Bye!\n";
			return (0);
		}
		else if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
	}
	return (1);
}
