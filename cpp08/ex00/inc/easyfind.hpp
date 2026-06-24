/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 21:21:21 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/24 21:21:22 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template <typename T>
class easyfind
{
	public:
		// Constructors
		easyfind( void );
		easyfind( const easyfind &cpy );

		// Arithmetic operators
		easyfind &operator=( const easyfind &rhs );

		// Destructor
		~easyfind( void );

		// Member functios
		T::iterator			*easyfind( T &cont, int i );
		T::const_iterator	*easyfind( T &cont, int i );
};

#endif
