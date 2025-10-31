/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:04:07 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/30 21:40:20 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>	// string

class	Zombie
{
	public:
		Zombie ( std::string name );
		~Zombie( void );

		void	announce( void );
	private:
		Zombie( void );
		
		std::string	_name;
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif /* ZOMBIE */
