/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:38:19 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/13 17:58:09 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/
Form::Form ( void ) :
	_name("Unknown"),
	_signed(0),
	_gradeToSign(1),
	_gradeToExec(1)
{
	//std::cout << "\033[90mVoid constructor called\033[0m" << std::endl;
	return ;
}

Form::Form ( const std::string, const int gradeToSign,
		const int gradeToExec ) :
	_name(name),
	_signed(0),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	std::cout << "\033[90mDefault constructor called\033[0m" << std::endl;
	return ;
}

Form::Form ( const Form &cpy)
{
	std::cout << "\033[90mCopy constructor called\033[0m" << std::endl;
	this->_signed = cpy._signed;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/

Form	&Form::operator=( const Form  &rhs )
{
	std::cout << "\033[90mCopy operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	this->_signed = rhs._signed;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

Form::~Form ( void )
{
	std::cout << "\033[90mDestructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*							MEMBER FUNCTIONS									*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/

