/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 23:14:26 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/04 21:02:53 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>		// cout

HumanA::HumanA ( std::string name, Weapon &weapon ) : _name(name), _weapon(weapon)
{
	return ;
}

HumanA::~HumanA ( void )
{
	return ;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attack with their ";
	std::cout << this->_weapon.getType() << std::endl;
}