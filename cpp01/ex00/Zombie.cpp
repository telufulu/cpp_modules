/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:11:28 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/30 21:38:00 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>		// cout

Zombie::Zombie( void )
{
	return ;
}

Zombie::~Zombie( void )
{
	return ;
}

Zombie::Zombie( std::string name ) : _name(name)
{
	return ;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
