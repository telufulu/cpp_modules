/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 23:03:43 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/31 23:31:28 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB ( std::string name );
		~HumanB ( void );

		void	attack( void );
		void	setWeapon( Weapon &weapon );
	
	private:
		HumanB ( void );

		std::string	_name;
		Weapon		*_weapon;
};

#endif /* HUMANB */
