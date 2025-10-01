/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:29:02 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/04 20:57:40 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>	//string

class	Weapon
{
	public:
		Weapon( std::string type );
		Weapon( void );
		~Weapon( void );

		void	setType( std::string type );
		std::string	&getType( void );

	private:
		std::string	_type;
};

#endif /* WEAPON */
