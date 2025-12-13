/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:10:45 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/13 17:57:51 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main ( void )
{
	std::cout << std::endl << "\033[36m###\t???\t###\033[0m"
		<< std::endl;	
	try {
		Bureaucrat	a("Daniel", 140);

		std::cout << a << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\033[31mError:\033[0m" << " Bureaucrat not created because "
			<< e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\033[31mError:\033[0m" << " Bureaucrat not created because "
			<< e.what() << std::endl;
	}
	return 0;
}
