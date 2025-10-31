/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 08:59:51 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/14 08:59:52 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
/* ************************************************************************** */
/*									CONSTRUCTORS							* */
/* ************************************************************************** */
Animal::Animal	( void ) : type("Random")
{
	std::cout << "\033[90mAnimal default constructor called\033[0m" << std::endl;
	return ;
}

Animal::Animal	( const Animal &cpy )
{
	std::cout << "\033[90mAnimal copy constructor called\033[0m" << std::endl;
	if (this == &cpy)
		return;
	this->type = cpy.getType();
	return ;
}

/* ************************************************************************** */
/*									OPERATORS								* */
/* ************************************************************************** */
Animal	&Animal::operator=( const Animal &rhs )
{
	if (this == &rhs)
		return *this;
	this->type = rhs.getType();
	return *this;
}

/* ************************************************************************** */
/*									DESTRUCTOR								* */
/* ************************************************************************** */
Animal::~Animal	( void )
{
	std::cout << "\033[90mAnimal destructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*								MEMBER FUNCTIONS							* */
/* ************************************************************************** */
void    Animal::makeSound( void ) const
{
    std::cout << "[ Strange sound. What is this random creature? ]" << std::endl;
}

std::string Animal::getType( void ) const
{
    return this->type;
}
/* ************************************************************************** */
/*								NON MEMBER FUNCTIONS						* */
/* ************************************************************************** */