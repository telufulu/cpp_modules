/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:51:49 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/03 17:13:05 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon ( void )
{	
	return ;
}

Weapon::~Weapon ( void )
{
	return ;
}

Weapon::Weapon ( std::string type ) : _type(type)
{	
	return ;
}

void	Weapon::setType ( std::string type )
{
	this->_type = type;
	return ;
}

std::string	&Weapon::getType( void )
{
	return (this->_type);
}