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

int	main ( void )
{
	std::cout << std::endl << "\033[36m###\tForm instatiation\t###\033[0m" << std::endl;
	Form gg("036", 0, )

	std::cout << std::endl << "\033[36m###\tGood behaviour\t###\033[0m" << std::endl;
	Bureaucrat	*good;

	try {
		good = new Bureaucrat("Ana", 50);
		std::cout << *good << std::endl;
		good->incrementGrade();
		std::cout << *good << std::endl;
		delete good;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\033[31mError:\033[0m " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\033[31mError:\033[0m " << e.what() << std::endl;
	}
	return 0;
}
