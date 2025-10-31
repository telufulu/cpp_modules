/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:26:44 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/27 13:47:43 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ):
	_firstName(""),
	_lastName(""),
	_nickname(""),
	_phoneNumber(""),
	_darkestSecret("")
{}

Contact::~Contact( void )
{
	return ;
}

void	Contact::set( std::string var, std::string content )
{
	if (var == "firstName")
		this->_firstName = content;
	else if (var == "lastName")
		this->_lastName = content;
	else if (var == "nickname")
		this->_nickname = content;
	else if (var == "phoneNumber")
		this->_phoneNumber = content;
	else if (var == "darkestSecret")
		this->_darkestSecret = content;
}

std::string	Contact::get( const std::string var )
{
	if (var == "firstName")
		return (this->_firstName);
	else if (var == "lastName")
		return (this->_lastName);
	else if (var == "nickname")
		return (this->_nickname);
	else if (var == "phoneNumber")
		return (this->_phoneNumber);
	else if (var == "darkestSecret")
		return (this->_darkestSecret);
	return (NULL);
}
