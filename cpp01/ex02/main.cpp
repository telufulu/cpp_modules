/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:01:21 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/31 20:15:47 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// string, cout

int	main( void )
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory address of str:\t\t" << &str << std::endl;
	std::cout << "Memory address of stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Memory address of stringREF:\t" << &stringREF << std::endl;
	
	std::cout << "\nValue of str:\t\t" << str << std::endl;
	std::cout << "Value of stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "Value of stringREF:\t" << stringREF << std::endl;
	return (0);
}
