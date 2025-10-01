/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 21:05:20 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/28 21:13:24 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class	ClapTrap
{
	public:
		//Constructors
		ClapTrap( void );					//default
		ClapTrap( const ClapTrap &cpy );	//copy

		//Operators
		ClapTrap &operator=( const ClapTrap &rhs );

		//Destructor
		~ClapTrap( void );

		
};

#endif /* CLAPTRAP */
