/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 23:03:43 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/04 21:03:02 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA ( std::string name, Weapon &weapon);
		~HumanA ( void );

		void	attack( void );
	
	private:
		HumanA ( void );

		std::string	_name;
		Weapon		&_weapon;
};

#endif /* HUMANA */
