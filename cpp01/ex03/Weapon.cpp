/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:51:49 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/31 23:34:35 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon ( void )
{
	return ;
}

Weapon::Weapon ( std::string type ) : _type(type)
{
	return ;
}

Weapon::~Weapon ( void )
{
	return ;
}

const std::string	&Weapon::getType( void )
{
	return(this->_type);
}

void Weapon::setType ( std::string value )
{
	this->_type = value;
	return ;
}
