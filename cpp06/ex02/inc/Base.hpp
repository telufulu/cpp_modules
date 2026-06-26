/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:56:34 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/18 13:56:36 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		// Destructor
		virtual ~Base( void );
	private:

};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

#endif
