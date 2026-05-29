/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:57:29 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/13 22:57:31 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>						// ofstream
#include <cstdlib>  					// rand, srand
#include <ctime>						// time

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/
RobotomyRequestForm::RobotomyRequestForm ( void ) :
	AForm("RobotomyRequest", 72, 35)
{
	std::cout << "\033[90mVoid constructor called\033[0m" << std::endl;
	srand(time(0));
	this->_num_rand = rand();
	return ;
}

RobotomyRequestForm::RobotomyRequestForm ( const std::string target ) :
	AForm("RobotomyRequest", 72, 35),
	_target(target)
{
	std::cout << "\033[90mDefault constructor called\033[0m" << std::endl;
	srand(time(0));
	this->_num_rand = rand();
	return ;
}

RobotomyRequestForm::RobotomyRequestForm ( const RobotomyRequestForm &cpy) :
	AForm(cpy.getName(), cpy.getSignPerm(), cpy.getExecPerm())
{
	std::cout << "\033[90mCopy constructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm  &rhs )
{
	std::cout << "\033[90mCopy operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

RobotomyRequestForm::~RobotomyRequestForm ( void )
{
	std::cout << "\033[90mDestructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*							MEMBER FUNCTIONS									*/
/* ****************************************************************************	*/
void	RobotomyRequestForm::formExecution( Bureaucrat const &executor ) const
{
    int random = rand() % 2 + 1;

	if (random % 2)
		throw RobotomyRequestForm::RobotomyException();
	std::cout << this->_target << " has been robotomized successfully by "
	<< executor.getName() << std::endl;
}

/* ************************************************************************** */
/*						EXCEPTION CLASSES		 			   				  */
/* ************************************************************************** */
const char	*RobotomyRequestForm::RobotomyException::what() const throw()
{
	return "robotomy failed";
}