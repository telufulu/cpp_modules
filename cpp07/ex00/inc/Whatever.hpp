/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:07:27 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/22 11:07:28 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

	template <typename T>
	void swap( T &a, T &b )
	{
		// Swaps the values of two given parameters. Does not return anything
		T	aux = a;

		a = b;
		b = aux;
	}

	template <typename T>
	T	min( T &a, T &b )
	{
		// Compares the two values passed as parameters and returns the smallest one.
		// If they are equal, it returns the second one
		if (a == b || a > b)
			return (b);
		else
			return (a);
	}

	template <typename T>
	T	max( T &a, T &b )
	{
		// Compares the two values passed as parameters and returns the greatest one.
		// If they are equal, it returns the second one.
		if (a == b || a < b)
			return (b);
		else
			return (a);
	}

#endif
