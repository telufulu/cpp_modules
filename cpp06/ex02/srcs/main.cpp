/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:56:08 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/18 13:56:11 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>		// rand
# include <iostream>	// cout

Base	*generate( void )
{
	switch (std::rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}

void	identify( Base *p )
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void	identify( Base &p )
{
	// If it fails, dynamic_cast throw std::bad_cast exception
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...)
	{
	} // default generic catch
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...)
	{
	}
	std::cout << "C" << std::endl;
}

int	main ( void )
{
	Base	*ptr;
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 3; ++i)
	{
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	return 0;
}
