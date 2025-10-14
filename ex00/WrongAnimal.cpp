/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 08:59:51 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/14 08:59:52 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
/* ************************************************************************** */
/*									CONSTRUCTORS							* */
/* ************************************************************************** */
WrongAnimal::WrongAnimal	( void ) : type("Random")
{
	std::cout << "\033[90mWrongAnimal default constructor called\033[0m" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal	( const WrongAnimal &cpy )
{
	std::cout << "\033[90mWrongAnimal copy constructor called\033[0m" << std::endl;
	if (this == &cpy)
		return;
	this->type = cpy.getType();
	return ;
}

/* ************************************************************************** */
/*									OPERATORS								* */
/* ************************************************************************** */
WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &rhs )
{
	if (this == &rhs)
		return *this;
	this->type = rhs.getType();
	return *this;
}

/* ************************************************************************** */
/*									DESTRUCTOR								* */
/* ************************************************************************** */
WrongAnimal::~WrongAnimal	( void )
{
	std::cout << "\033[90mWrongAnimal destructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*								MEMBER FUNCTIONS							* */
/* ************************************************************************** */
void    WrongAnimal::makeSound( void ) const
{
    if (!type.empty() && type == "WrongCat")
        std::cout << "Miau??" << std::endl;
    else
        std::cout << "[ Strange sound. This can't be an animal... ]" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
    return this->type;
}
/* ************************************************************************** */
/*								NON MEMBER FUNCTIONS						* */
/* ************************************************************************** */