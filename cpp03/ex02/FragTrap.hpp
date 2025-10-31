/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:19:35 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/13 19:19:36 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class   FragTrap:   public ClapTrap
{
    public:
		//Constructors
		FragTrap( void );					//default
		FragTrap( const std::string &name );
		FragTrap( const FragTrap &cpy );	//copy

		//Operators
		FragTrap		&operator=( const FragTrap &rhs );

		//Destructor
		~FragTrap( void );

        // Member functions
        void    highFivesGuys( void );
};
#endif /* FRAGTRAP */