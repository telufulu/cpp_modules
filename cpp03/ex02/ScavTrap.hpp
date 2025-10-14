/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:19:35 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/13 19:19:36 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class   ScavTrap:   public ClapTrap
{
    public:
		//Constructors
		ScavTrap( void );					//default
		ScavTrap( const std::string &name );
		ScavTrap( const ScavTrap &cpy );	//copy

		//Operators
		ScavTrap		&operator=( const ScavTrap &rhs );

		//Destructor
		~ScavTrap( void );

        // Member functions
		void	attack( const std::string& target );
        void    guardGate( void );
};
#endif /* SCAVTRAP */