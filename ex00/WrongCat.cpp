/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:27:12 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/14 09:27:13 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ************************************************************************** */
/*									CONSTRUCTORS							* */
/* ************************************************************************** */
WrongCat::WrongCat	( void )
{
	std::cout << "\033[90mWrongCat default constructor called\033[0m" << std::endl;
	this->type = "WrongCat";
	return ;
}

WrongCat::WrongCat	( const WrongCat &cpy ) : WrongAnimal(cpy)
{
	std::cout << "\033[90mWrongCat copy constructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*									OPERATORS								* */
/* ************************************************************************** */
WrongCat	&WrongCat::operator=( const WrongCat &rhs )
{
	if (this == &rhs)
		return *this;
	WrongAnimal::operator=(rhs);
	return *this;
}

/* ************************************************************************** */
/*									DESTRUCTOR								* */
/* ************************************************************************** */
WrongCat::~WrongCat	( void )
{
	std::cout << "\033[90mWrongCat destructor called\033[0m" << std::endl;
	return ;
}
