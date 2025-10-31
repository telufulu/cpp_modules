/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 21:05:15 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/02 19:57:13 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/*									CONSTRUCTORS							* */
/* ************************************************************************** */
ClapTrap::ClapTrap	( void ) : 
	_name("NO NAME"),
	_hitPoints(0),
	_energyPoints(0),
	_attackDamage(0)
{
	std::cout << "\033[90mDefault constructor called\033[0m" << std::endl;
	return ;
}

ClapTrap::ClapTrap	( const std::string &name ) : 
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "\033[90mName constructor called\033[0m" << std::endl;
	return ;
}

ClapTrap::ClapTrap	( const ClapTrap &cpy )
{
	std::cout << "\033[90mCopy constructor called\033[0m" << std::endl;
	if (this == &cpy)
		return;
	this->_name = cpy.getName();
	this->_hitPoints = cpy.getHitPoints();
	this->_energyPoints = cpy.getEnergyPoints();
	this->_attackDamage = cpy.getAttackDamage();
	return ;
}

/* ************************************************************************** */
/*									OPERATORS								* */
/* ************************************************************************** */
ClapTrap	&ClapTrap::operator=( const ClapTrap &rhs )
{
	if (this == &rhs)
		return *this;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	return *this;
}

/* ************************************************************************** */
/*									DESTRUCTOR								* */
/* ************************************************************************** */
ClapTrap::~ClapTrap	( void )
{
	std::cout << "\033[90mDestructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*								MEMBER FUNCTIONS							* */
/* ************************************************************************** */
std::string		ClapTrap::getName( void ) const
{
	return this->_name;
}

unsigned int	ClapTrap::getHitPoints( void ) const
{
	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints( void ) const
{
	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackDamage( void ) const
{
	return this->_attackDamage;
}

void			ClapTrap::set( const std::string var, unsigned int val)
{
	int			i = 0;
	std::string	values[] = { "hitPoints", "energyPoints", "attackDamage" };

	while (!values[i].empty() && values[i] != var )
		++i;
	switch (i)
	{
		case 0:
			this->_hitPoints = val;
			break ;
		case 1:
			this->_energyPoints = val;
			break ;
		case 2:
			this->_attackDamage = val;
			break ;
	}
	return ;
}

void			ClapTrap::attack( const std::string &target )
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead " << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enough movements " << std::endl;
		return ;
	}
	--this->_energyPoints;
	std::cout << "ClapTrap " << this->_name << " attacks " << target;
	std::cout << " causing " << this->_attackDamage << " points of damage!" << std::endl;
	return ;
}

void			ClapTrap::takeDamage ( unsigned int amount )
{
if (this->_hitPoints < amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	return ;
}

void			ClapTrap::beRepaired ( unsigned int amount )
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead " << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have enough movements " << std::endl;
		return ;
	}
	--this->_energyPoints;
	std::cout << "ClapTrap " << this->_name << " heales " << amount << "HP" << std::endl;
	this->_hitPoints += amount;
	return ;
}

/* ************************************************************************** */
/*								NON MEMBER FUNCTIONS						* */
/* ************************************************************************** */
