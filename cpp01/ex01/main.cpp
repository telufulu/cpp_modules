/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:35:56 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/31 19:58:06 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	int		numZombies = 420;
	Zombie	*zombie = zombieHorde(numZombies, "Sam");
	
	while (numZombies--)
		zombie->announce();
	return (0);
}
