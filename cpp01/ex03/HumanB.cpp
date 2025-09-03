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

HumanA::HumanB ( void )
{
	return ;
}

HumanA::~HumanB ( void )
{
	return ;
}

HumanA::HumanB ( std::string name ) : _name(name)
{
	return ;
}

void	HumanB::attack( void )
{
	std::cout << this->_name << "attacks with their ";
	if (this->_weapon)
		std::cout << this->_weapon.type;
	std::endl;
}

void	HumanB::setWeapon( Weapon weapon)
{
	&this->_weapon = weapon;
	return ;
}
