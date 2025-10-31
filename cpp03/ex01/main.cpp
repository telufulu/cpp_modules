/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 21:05:23 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/02 19:54:59 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	status( const ClapTrap &a, const ClapTrap &b)
{
	std::cout << a.getName() << "\t" << a.getEnergyPoints() << "PM " << a.getHitPoints() << "HP" << std::endl;
	std::cout << b.getName() << "\t" << b.getEnergyPoints() << "PM " << b.getHitPoints() << "HP" << std::endl;
}

int	main( void )
{
	ClapTrap a("R2-D2");
	ScavTrap b("Marvin");
	ClapTrap c;

	c.attack("Prueba");
	c = b;

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	status(a, b);
	std::cout << std::endl;
	
	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());
	status(a, b);
	std::cout << std::endl;
	
	a.beRepaired(5);
	c.attack(b.getName());
	b.takeDamage(c.getAttackDamage());
	status(b, c);
	std::cout << std::endl;

	b.guardGate();
	return 0;
}
