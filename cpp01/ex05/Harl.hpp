/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:26:27 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/22 21:26:28 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class	Harl
{
	public:
		Harl( void );
		~Harl( void );

		void	complain( std::string level );

	private:
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );
};
#endif /* HARL */