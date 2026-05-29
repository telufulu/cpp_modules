/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:10:37 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/13 17:09:13 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* ************************************************************************** */
/*							CONSTRUCTORS									  */
/* ************************************************************************** */

Bureaucrat::Bureaucrat ( void ) :
	_grade(150),
	_name("Unknown")
{
	//std::cout << "\033[90mVoid constructor called\033[0m" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat ( const std::string name, const int grade ) : 
	_grade(grade),
	_name(name)
{
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	std::cout << "\033[90mDefault constructor called\033[0m" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat ( const Bureaucrat &cpy) :
	_grade(cpy._grade),
	_name(cpy._name)
{
	std::cout << "\033[90mCopy constructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*							OPERATORS					    				  */
/* ************************************************************************** */

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat  &rhs )
{
	std::cout << "\033[90mCopy operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	this->_grade = rhs._grade;
	return *this;
}

/* ************************************************************************** */
/*							DESTRUCTOR										  */
/* ************************************************************************** */

Bureaucrat::~Bureaucrat ( void )
{
	std::cout << "\033[90mDestructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*						MEMBER FUNCTIONS				    				  */
/* ************************************************************************** */
std::string	Bureaucrat::getName( void ) const
{
	return this->_name;
}

int			Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void		Bureaucrat::incrementGrade( void )
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void		Bureaucrat::decrementGrade( void )
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

void		Bureaucrat::signForm( AForm &obj )
{
	try {
		obj.beSigned(*this);
		std::cout << this->getName() << " signed " << obj.getName() << " form ✅" 
			<< std::endl;
	} catch (const AForm::GradeTooLowException &e) {
		std::cerr << obj.getName() << " cannot be signed by " << this->getName()
			<< ": \033[31m" << e.what() << "\033[0m " << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const &form)
{
	form.execute(*this);
	std::cout << this->_name << " executed " << form.getName() << std::endl;
}
/* ************************************************************************** */
/*						NON MEMBER FUNCTIONS			    				  */
/* ************************************************************************** */
std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}

/* ************************************************************************** */
/*						EXCEPTION CLASSES		 			   				  */
/* ************************************************************************** */
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}
