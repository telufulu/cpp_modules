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

# include <algorithm>		// iterator
# include <stdexcept>		// runtime_error

template <typename T>
typename T::iterator	easyfind( T &cont, int i )
{
	typename T::iterator	it;
	
	it = std::find(cont.begin(), cont.end(), i);
	if (it == cont.end())
		throw std::runtime_error("not found");
	return it;
}

#endif
