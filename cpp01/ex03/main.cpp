/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:56:00 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/31 23:37:59 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>		// cout

int	main ( void )
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	/*{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}*/
	return (0);
}
