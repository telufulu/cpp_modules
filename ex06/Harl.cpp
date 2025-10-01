/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:26:34 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/22 21:26:36 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl ( void )
{
	return ;
}

Harl::~Harl ( void )
{
	return ;
}

void	Harl::complain( std::string level)
{
	int				i = 0;
	std::string		names[] = { "debug", "info", "warning", "error" };
	
	while (!names[i].empty() && names[i] != level)
		++i;
	switch (i)
	{
		case 0:
			this->_debug();
		case 1:
			this->_info();
		case 2:
			this->_warning();
		case 3:
			this->_error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return ;
}

void	Harl::_debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::_info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money" << std::endl;
	return ;
}

void	Harl::_warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	return ;
}

void	Harl::_error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}