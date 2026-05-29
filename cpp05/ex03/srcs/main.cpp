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
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main ( void )
{
	std::cout << std::endl << "\033[36m###\tForm created by an intern\t###\033[0m" << std::endl;
	try {	
		Bureaucrat	a("Daniel", 15);
		Intern		b;
		AForm		*z = 0;

		std::cout << a << std::endl;
		try {
			z = b.makeForm("asdasd", "Madrid");
			z->beSigned(a);
			std::cout << *z << std::endl;
			delete z;
		} catch (const std::exception &e) {
			std::cout << "Intern doesn't create form: \033[31m"
			<< e.what() << "\033[0m" << std::endl;
		}
		try {
			z = b.makeForm("ShrubberyCreationForm", "Madrid");
			z->beSigned(a);
			a.executeForm(*z);
			std::cout << *z << std::endl;
			delete z;
		} catch (const std::exception &e) {
			std::cout << "Intern doesn't create form: \033[31m"
			<< e.what() << "\033[0m" << std::endl;
		}
	} catch (const std::exception &e) {
		std::cout << "\033[31m Error: \033[0m" << e.what() << std::endl;
	}
	return 0;
}