/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:27:12 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/15 09:06:40 by telufulu         ###   ########.fr       */
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

Cat::Cat	( const Cat &cpy ) : AAnimal(cpy)
{
	std::cout << "\033[90mCat copy constructor called\033[0m" << std::endl;
	this->_brain = new Brain(*cpy._brain);
	return ;
}

/* ************************************************************************** */
/*									OPERATORS								* */
/* ************************************************************************** */
Cat	&Cat::operator=( const Cat &rhs )
{
	if (this == &rhs)
		return *this;
	AAnimal::operator=(rhs);
	*this->_brain = *rhs._brain;
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

/* ************************************************************************** */
/*								MEMBER FUNCTIONS							* */
/* ************************************************************************** */

void	Cat::setIdea( std::string idea )
{
	this->_brain->setIdea(idea);
	return ;
}

const std::string	&Cat::getIdea( unsigned int i ) const
{
	return this->_brain->getIdea(i);
}

void    Cat::makeSound( void ) const
{
    std::cout << "Miauu" << std::endl;
}