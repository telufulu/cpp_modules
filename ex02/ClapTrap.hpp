/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 21:05:20 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/02 19:47:09 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap
{
	public:
		//Constructors
		ClapTrap( void );					//default
		ClapTrap( const std::string &name );
		ClapTrap( const ClapTrap &cpy );	//copy

		//Operators
		ClapTrap		&operator=( const ClapTrap &rhs );

		//Destructor
		~ClapTrap( void );

		// Member functions
		std::string		getName( void ) const;
		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getAttackDamage( void ) const;
		void			set( const std::string var, unsigned int val);

		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif /* CLAPTRAP */
