/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:26:50 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/27 13:34:16 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>	// string

class	Contact
{
	public:
		Contact( void );
		~Contact( void );

		void		set( const std::string var, std::string content );
		std::string	get( const std::string var);

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string	_phoneNumber;
		std::string _darkestSecret;
};

#endif
