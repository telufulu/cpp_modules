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
	int				i = -1;
	std::string		names[] = { "debug", "info", "warning", "error" };
	void			(Harl::*func[])() = { 
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error,
	};
	
	while (!names[++i].empty())
		if (level == names[i])
			(this->*func[i])();
	return ;
}

void	Harl::_debug( void )
{
	std::cout << "DEBUG: \"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\"" << std::endl;
	return ;
}

void	Harl::_info( void )
{
	std::cout << "INFO: \"I cannot believe adding extra bacon costs more money\"" << std::endl;
	return ;
}

void	Harl::_warning( void )
{
	std::cout << "WARNING: \"I think I deserve to have some extra bacon for free.\"" << std::endl;
	return ;
}

void	Harl::_error( void )
{
	std::cout << "ERROR: \"This is unacceptable! I want to speak to the manager now.\"" << std::endl;
	return ;
}