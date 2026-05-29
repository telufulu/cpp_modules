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
#include "Form.hpp"

int	main ( void )
{
	std::cout << std::endl << "\033[36m###\tForm instatiation\t###\033[0m" 
		<< std::endl;
	Form gg("036", 40, 50);

	std::cout << gg << std::endl;
	std::cout << std::endl << "\033[36m###\tTry to sign form from Form class\t###\033[0m" 
		<< std::endl;
	try {
		Bureaucrat	a("Ana", 50);
		Bureaucrat 	b("Charles", 2);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		try {
			gg.beSigned(a);
			std::cout << a.getName() << " signed " << gg.getName() << " form ✅" 
				<< std::endl;
		} catch (const Form::GradeTooLowException &e) {
			std::cerr << gg.getName() << " cannot be signed by " << a.getName()
				<< ": \033[31m" << e.what() << "\033[0m " << std::endl;
		}
		try {
			gg.beSigned(b);
			std::cout << b.getName() << " signed " << gg.getName() << " form ✅" 
				<< std::endl;
		} catch (const Form::GradeTooLowException &e) {
			std::cerr << gg.getName() << " cannot be signed by " << a.getName()
				<< ": \033[31m" << e.what() << "\033[0m " << std::endl;
		}
		std::cout << std::endl << gg << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\033[31mError:\033[0m" << " Bureaucrat not created because "
			<< e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\033[31mError:\033[0m" << " Bureaucrat not created because "
			<< e.what() << std::endl;
	}
	
	std::cout << std::endl << "\033[36m###\tTry to sign form from Bureaucrat class\t###\033[0m"
		<< std::endl;	
	try {
		Bureaucrat	c("Daniel", 140);
		Form		x("B26", 140, 1);

		std::cout << c << std::endl;
		try {
			c.signForm(x);
			std::cout << x << std::endl;
		} catch (const Form::GradeTooLowException &e) {
		std::cerr << x.getName() << " cannot be signed by " << c.getName()
			<< ": \033[31m" << e.what() << "\033[0m " << std::endl;
		} 
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\033[31mError:\033[0m" << " Bureaucrat not created because "
			<< e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\033[31mError:\033[0m" << " Bureaucrat not created because "
			<< e.what() << std::endl;
	}
	return 0;
}
