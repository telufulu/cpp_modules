/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:57:29 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/13 22:57:31 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>						// ofstream

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/
PresidentialPardonForm::PresidentialPardonForm ( void ) :
	AForm("PresidentialPardon", 25, 5)
{
	std::cout << "\033[90mVoid constructor called\033[0m" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm ( const std::string target ) :
	AForm("PresidentialPardon", 25, 5),
	_target(target)
{
	std::cout << "\033[90mDefault constructor called\033[0m" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm ( const PresidentialPardonForm &cpy) :
	AForm(cpy.getName(), cpy.getSignPerm(), cpy.getExecPerm())
{
	std::cout << "\033[90mCopy constructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm  &rhs )
{
	std::cout << "\033[90mCopy operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

PresidentialPardonForm::~PresidentialPardonForm ( void )
{
	std::cout << "\033[90mDestructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*							MEMBER FUNCTIONS									*/
/* ****************************************************************************	*/
void	PresidentialPardonForm::formExecution( Bureaucrat const &executor ) const
{
	(void)executor;
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." 
	<< std::endl;
}

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
