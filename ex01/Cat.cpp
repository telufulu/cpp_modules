/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:27:12 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/14 09:27:13 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/*									CONSTRUCTORS							* */
/* ************************************************************************** */
Cat::Cat	( void )
{
	std::cout << "\033[90mCat default constructor called\033[0m" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
	return ;
}

Cat::Cat	( const Cat &cpy ) : Animal(cpy)
{
	std::cout << "\033[90mCat copy constructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*									OPERATORS								* */
/* ************************************************************************** */
Cat	&Cat::operator=( const Cat &rhs )
{
	if (this == &rhs)
		return *this;
	Animal::operator=(rhs);
	return *this;
}

/* ************************************************************************** */
/*									DESTRUCTOR								* */
/* ************************************************************************** */
Cat::~Cat	( void )
{
	std::cout << "\033[90mCat destructor called\033[0m" << std::endl;
	delete this->_brain;
	return ;
}
