/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:10:37 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/09 00:10:40 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	std::cout << "\033[90mDefault constructor called\033[0m" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat ( const Bureaucrat &cpy) :
	_grade(cpy._grade),
	_name(cpy._name)
{
	//std::cout << "\033[90mCopy constructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*							OPERATORS					    				  */
/* ************************************************************************** */

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat  &rhs )
{
	//std::cout << "\033[90mCopy operator called\033[0m" << std::endl;
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
	//std::cout << "\033[90mDestructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*						MEMBER FUNCTIONS				    				  */
/* ************************************************************************** */
std::string	Bureaucrat::getName( void ) const
{
	return this->_name;
}

int	Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

/* ************************************************************************** */
/*						NON MEMBER FUNCTIONS			    				  */
/* ************************************************************************** */
std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}