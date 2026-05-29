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
#include "PresidentialPardonForm.hpp"

int	main ( void )
{
	std::cout << std::endl << "\033[36m###\tSchubbery form\t###\033[0m" << std::endl;
	try {
		Bureaucrat	a("Daniel", 14);
		ShrubberyCreationForm z("Patata");

		std::cout << a << std::endl;
		try {
			z.beSigned(a);
			std::cout << z << std::endl;
			try {
				a.executeForm(z);
			} catch (const ShrubberyCreationForm::GradeTooLowException &e){
				std::cout << "Bureaucrat " << a.getName() << " cannot execute "
				<< z.getName() << " form: \033[31m" << e.what() 
				<< "\033[0m" << std::endl;
			} catch (const ShrubberyCreationForm::NotSignedException &e){
				std::cout << z.getName() << " cannot be executed: \033[31m" 
				<< e.what() << "\033[0m" << std::endl;
			}
		} catch (const ShrubberyCreationForm::GradeTooLowException &e){
			std::cout << "Bureaucrat " << a.getName() << " cannot sign "
			<< z.getName() << " form: \033[31m" << e.what() 
			<< "\033[0m" << std::endl;
		}
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\033[31mError:\033[0m" << " Bureaucrat not created because "
			<< e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\033[31mError:\033[0m" << " Bureaucrat not created because "
			<< e.what() << std::endl;
	}

	std::cout << std::endl << "\033[36m###\tRobotomy form\t###\033[0m" << std::endl;
	try {
		Bureaucrat b("Irene", 30);
		RobotomyRequestForm	x("Boniato");

		std::cout << b << std::endl;
		try {
			x.beSigned(b);
			std::cout << x << std::endl;
			try {
				b.executeForm(x);
			} catch (const std::exception &e){
				std::cout << "Bureaucrat " << b.getName() << " cannot execute "
				<< x.getName() << " form: \033[31m" << e.what() 
				<< "\033[0m" << std::endl;
			}
		} catch (const RobotomyRequestForm::GradeTooLowException &e){
			std::cout << "Bureaucrat " << b.getName() << " cannot sign "
			<< x.getName() << " form: \033[31m" << e.what() 
			<< "\033[0m" << std::endl;
		}
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\033[31mError:\033[0m" << " Bureaucrat not created because "
			<< e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\033[31mError:\033[0m" << " Bureaucrat not created because "
			<< e.what() << std::endl;
	}

	std::cout << std::endl << "\033[36m###\tPresidential Pardon Form\t###\033[0m" << std::endl;
	try {
		Bureaucrat				c("Rachel", 5);
		PresidentialPardonForm	y("Madrid");

		std::cout << c << std::endl;
		try {
			c.signForm(y);
		} catch (const std::exception &e) {
			std::cout << "Bureaucrat " << c.getName() << " cannot sign "
			<< y.getName() << " form: \033[31m" << e.what() 
			<< "\033[0m" << std::endl;
		}
		try {
			c.executeForm(y);
		} catch (const std::exception &e) {
			std::cout << "Bureaucrat " << c.getName() << " cannot execute "
			<< y.getName() << " form: \033[31m" << e.what() 
			<< "\033[0m" << std::endl;
		}
		try {
			c.decrementGrade();
		} catch (const std::exception &e) {
			std::cout << "Is not possible to change " << c.getName() <<
			"'s grade. Reason: " << e.what() << std::endl;
		}
		try {
			c.executeForm(y);
		} catch (const std::exception &e) {
			std::cout << "Bureaucrat " << c.getName() << " cannot execute "
			<< y.getName() << " form: \033[31m" << e.what() 
			<< "\033[0m" << std::endl;
		}
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}