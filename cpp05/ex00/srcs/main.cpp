/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:10:45 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/13 17:53:00 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main ( void )
{
	std::cout << std::endl << "\033[36m###\tGood copy behaviour\t###\033[0m" << std::endl;
	Bureaucrat x("Xavier", 30);
	Bureaucrat y(x);
	Bureaucrat z("Mary", 15);

	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
	z = x;
	std::cout << z << std::endl;

	std::cout << "\033[36m###\tHigh exception\t###\033[0m" << std::endl;
	Bureaucrat	*high = 0;
	try {
		high = new Bureaucrat("María", 160);
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\033[31mError:\033[0m " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\033[31mError:\033[0m " << e.what() << std::endl;
	}
	if (high)
	{
		std::cout << *high << std::endl;
		delete high;
	}

	std::cout << std::endl << "\033[36m###\tLow exception\t###\033[0m" << std::endl;
	try {
		Bureaucrat	low("Pablo", -4);
		std::cout << low << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\033[31mError:\033[0m " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\033[31mError:\033[0m " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[36m###\tDecrement exception\t###\033[0m" << std::endl;
	try {
		Bureaucrat	a("Jose", 150);
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\033[31mError:\033[0m " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\033[31mError:\033[0m " << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[36m###\tIncrement exception\t###\033[0m" << std::endl;
	try {
		Bureaucrat	b("Belén", 1);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\033[31mError:\033[0m " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\033[31mError:\033[0m " << e.what() << std::endl;
	}

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
