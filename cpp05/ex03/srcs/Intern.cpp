/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:45:39 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/14 16:45:40 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/

Intern::Intern ( void )
{
	std::cout << "\033[90mDefault Intern constructor called\033[0m" << std::endl;
	return ;
}

Intern::Intern ( const Intern &cpy)
{
	std::cout << "\033[90mCopy Intern constructor called\033[0m" << std::endl;
	(void)cpy;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/

Intern	&Intern::operator=( const Intern  &rhs )
{
	std::cout << "\033[90mCopy Intern operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

Intern::~Intern ( void )
{
	std::cout << "\033[90mIntern destructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*							MEMBER FUNCTIONS									*/
/* ****************************************************************************	*/
AForm		*Intern::makeForm(const std::string form, const std::string target)
{
	int	index = 0;
	std::string	forms[3] = { "ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"};
	
	while ( index < 3 && form != forms[index] )
		++index;
	if ( index < 3 )
		std::cout << "Intern created " << form << std::endl;
	switch (index)
	{
		case 0:
			return new ShrubberyCreationForm(target);
			break ;
		case 1:
			return new RobotomyRequestForm(target);
			break ;
		case 2:
			return new PresidentialPardonForm(target);
			break ;
		default:
			throw Intern::IDontKnowException();
	}
	return 0;
}
/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const Intern &obj)
{
	out << "This is an Intern class" << std::endl;
	(void)obj;
	return out;
}

/* ************************************************************************** */
/*						EXCEPTION CLASSES		 			   				  */
/* ************************************************************************** */
const char	*Intern::IDontKnowException::what() const throw()
{
	return "Inter doesn't understand the task";
}
