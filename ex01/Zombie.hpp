/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:04:07 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/31 19:54:55 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>	// string

class	Zombie
{
	public:
		Zombie( void );
		Zombie ( std::string name );
		~Zombie( void );

		void	announce( void );
		void	setName( std::string name );
	private:
		
		std::string	_name;
};

Zombie	*zombieHorde( int N, std::string name );

#endif /* ZOMBIE */
