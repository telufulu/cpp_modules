/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:29:02 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/31 23:33:53 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>	//string

class	Weapon
{
	public:
		Weapon( std::string type );
		~Weapon( void );

	const std::string	&getType( void );
	void				setType( std::string value );

	private:
		Weapon( void );
		std::string	_type;
};

#endif /* WEAPON */
