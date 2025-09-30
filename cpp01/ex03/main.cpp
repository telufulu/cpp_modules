/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:56:00 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/05 11:06:13 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>		// cout

int	main ( void )
{
	Weapon weaponA = Weapon("sword");
	HumanA adora("Adora", weaponA);
	Weapon weaponB = Weapon("claws");
	HumanB catra("Catra");
	
	// Adora ataca con su espada
	adora.attack();
	// Catra saca sus garras y ataca
	catra.setWeapon(weaponB);
	catra.attack();
	// Adora se convierte en She-Ra y ataca
	weaponA.setType("She-Ra sword");
	adora.attack();
	//Catra coge un garrote y ataca
	weaponB.setType("club");
	catra.attack();
	//Catra coge la espada de Adora y ataca
	catra.setWeapon(weaponA);
	catra.attack();

	return (0);
}
