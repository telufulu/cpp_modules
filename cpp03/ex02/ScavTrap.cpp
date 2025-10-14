/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:19:41 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/13 19:19:42 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/*									CONSTRUCTORS							* */
/* ************************************************************************** */
ScavTrap::ScavTrap	( void ) : ClapTrap()
{
	std::cout << "\033[90mDefault ScavTrap constructor called\033[0m" << std::endl;
	return ;
}

ScavTrap::ScavTrap	( const std::string &name ) : ClapTrap(name)
{
	std::cout << "\033[90mScavTrap name constructor called\033[0m" << std::endl;
	this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    return ;
}

ScavTrap::ScavTrap	( const ScavTrap &cpy ) : ClapTrap(cpy)
{
	std::cout << "\033[90mScavTrap copy constructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*									OPERATORS								* */
/* ************************************************************************** */
ScavTrap	&ScavTrap::operator=( const ScavTrap &rhs )
{
	if (this == &rhs)
		return *this;
	ClapTrap::operator=(rhs);
	return *this;
}

/* ************************************************************************** */
/*									DESTRUCTOR								* */
/* ************************************************************************** */
ScavTrap::~ScavTrap	( void )
{
	std::cout << "\033[90mScavTrap destructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*								MEMBER FUNCTIONS							* */
/* ************************************************************************** */

void			ScavTrap::attack( const std::string &target )
{
    if (this->_hitPoints == 0)
	{
		std::cout << this->_name << " is dead " << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " doesn't have enough movements " << std::endl;
		return ;
	}
	--this->_energyPoints;
	std::cout << "ScavTrap " << this->_name << " attacks " << target;
	std::cout << " causing " << this->_attackDamage << " points of damage!" << std::endl;
	return ;
}

void            ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap " << this->_name << " is in Gate keeper mode" << std::endl;
}
/* ************************************************************************** */
/*								NON MEMBER FUNCTIONS						* */
/* ************************************************************************** */
