/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 23:14:26 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/31 23:31:35 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB ( std::string name ) : _name(name), _weapon(NULL)
{
	return ;
}

HumanB::~HumanB ( void )
{
	return ;
}

void	HumanB::attack( void )
{
	std::cout << this->_name << " attack with their ";
	std::cout << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon ( Weapon &weapon )
{
	this->_weapon = &weapon;
}