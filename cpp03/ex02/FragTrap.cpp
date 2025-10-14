/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:19:41 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/13 19:19:42 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/*									CONSTRUCTORS							* */
/* ************************************************************************** */
FragTrap::FragTrap	( void ) : ClapTrap()
{
	std::cout << "\033[90mDefault FragTrap constructor called\033[0m" << std::endl;
	return ;
}

FragTrap::FragTrap	( const std::string &name ) : ClapTrap(name)
{
	std::cout << "\033[90mFragTrap name constructor called\033[0m" << std::endl;
	this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    return ;
}

FragTrap::FragTrap	( const FragTrap &cpy ) : ClapTrap(cpy)
{
	std::cout << "\033[90mFragTrap copy constructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*									OPERATORS								* */
/* ************************************************************************** */
FragTrap	&FragTrap::operator=( const FragTrap &rhs )
{
	if (this == &rhs)
		return *this;
	ClapTrap::operator=(rhs);
	return *this;
}

/* ************************************************************************** */
/*									DESTRUCTOR								* */
/* ************************************************************************** */
FragTrap::~FragTrap	( void )
{
	std::cout << "\033[90mFragTrap destructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*								MEMBER FUNCTIONS							* */
/* ************************************************************************** */

void            FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap " << this->_name << " says: 'High fives guys!'" << std::endl;
}
/* ************************************************************************** */
/*								NON MEMBER FUNCTIONS						* */
/* ************************************************************************** */
