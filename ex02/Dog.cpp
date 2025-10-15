/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:27:12 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/15 09:06:32 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*									CONSTRUCTORS							* */
/* ************************************************************************** */
Dog::Dog	( void )
{
	std::cout << "\033[90mDog default constructor called\033[0m" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
	return ;
}

Dog::Dog	( const Dog &cpy ) : AAnimal(cpy)
{
	std::cout << "\033[90mDog copy constructor called\033[0m" << std::endl;
	this->_brain = new Brain(*cpy._brain);
	return ;
}

/* ************************************************************************** */
/*									OPERATORS								* */
/* ************************************************************************** */
Dog	&Dog::operator=( const Dog &rhs )
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
Dog::~Dog	( void )
{
	std::cout << "\033[90mDog destructor called\033[0m" << std::endl;
	delete this->_brain;
	return ;
}

/* ************************************************************************** */
/*								MEMBER FUNCTIONS							* */
/* ************************************************************************** */

void	Dog::setIdea( std::string idea )
{
	this->_brain->setIdea(idea);
	return ;
}

const std::string	&Dog::getIdea( int i ) const
{
	return this->_brain->getIdea(i);
}

void	Dog::makeSound( void ) const
{
	std::cout << "Miauu" << std::endl;
}
