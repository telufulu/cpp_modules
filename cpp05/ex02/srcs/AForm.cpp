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

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/
AForm::AForm ( void ) :
	_name("Unknown"),
	_signed(0),
	_gradeToSign(1),
	_gradeToExec(1)
{
	//std::cout << "\033[90mVoid constructor called\033[0m" << std::endl;
	return ;
}

AForm::AForm ( const std::string name, const int gradeToSign,
		const int gradeToExec ) :
	_name(name),
	_signed(0),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	std::cout << "\033[90mDefault constructor called\033[0m" << std::endl;
	return ;
}

AForm::AForm ( const AForm &cpy ) :
	_name(cpy._name),
	_gradeToSign(cpy._gradeToSign),
	_gradeToExec(cpy._gradeToExec)
{
	std::cout << "\033[90mCopy constructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/

AForm	&AForm::operator=( const AForm  &rhs )
{
	std::cout << "\033[90mCopy operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

AForm::~AForm ( void )
{
	std::cout << "\033[90mDestructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*							MEMBER FUNCTIONS									*/
/* ****************************************************************************	*/
std::string	AForm::getName( void ) const
{
	return this->_name;
}

bool		AForm::isSigned( void ) const
{
	return this->_signed;
}

int			AForm::getSignPerm( void ) const
{
	return this->_gradeToSign;
}

int			AForm::getExecPerm( void ) const
{
	return this->_gradeToExec;
}

void		AForm::beSigned( Bureaucrat &obj )
{
	if (this->_gradeToSign < obj.getGrade())
		throw AForm::GradeTooLowException();
	this->_signed = 1;
}
/* ************************************************************************** */
/*						NON MEMBER FUNCTIONS			    				  */
/* ************************************************************************** */
std::ostream	&operator<<(std::ostream &out, const AForm &obj)
{
	out << "\033[97m~ " << obj.getName() << " form status ~\033[0m" << std::endl;
	out << "Sign permissions: " << obj.getSignPerm() << std::endl
		<< "Exec permissions: " << obj.getExecPerm() << std::endl;
	out << std::endl;
	if (obj.isSigned())
		out << "Signed ✅" << std::endl;
	else
		out << "Not signed ❌" << std::endl;
	return out;
}

/* ************************************************************************** */
/*						EXCEPTION CLASSES		 			   				  */
/* ************************************************************************** */
const char	*AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}