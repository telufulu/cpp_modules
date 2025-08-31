/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:31:10 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/30 21:45:26 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>		// cout

int	main( void )
{
	Zombie	*pepa;

	randomChump("Luis");
	pepa = newZombie("Pepa");
	//std::cout << pepa->announce << std::endl;
	delete pepa;
	return (0);
}
