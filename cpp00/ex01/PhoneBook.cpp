/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:01:10 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/26 17:24:49 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook( void )
{
	return ;
}

PhoneBook::~PhoneBook( void )
{
	return ;
}

void	PhoneBook::add( Contact *contacts )
{
	std::string	aux;

	if (this->_index == 8)
		this->_index == 0;
	std::cin >> aux
	contacts[index].set("firstName", aux);
	++this->_index;
}

std::string	PhoneBook::search( void )
{
	std::string	var;

	std::cin >> var;
	return (NULL);
}
