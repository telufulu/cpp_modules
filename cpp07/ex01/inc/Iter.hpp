/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:06:16 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/22 11:06:17 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>	//size_t

	template <typename T, typename F>
	void	iter( T *array, const size_t b, F f)
	{
		// Takes 3 parameters and returns nothing.
		// • The first parameter is the address of an array.
		// • The second one is the length of the array, passed as a const value.
		// • The third one is a function that will be called on every element of the array.
		// The function passed as the third parameter may take its argument by const reference
		// or non-const reference, depending on the context.

		for (size_t i = 0; i < b ; ++i)
			f(array[i]);
	}

#endif
