/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:01:10 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/27 14:09:09 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook( void )
{
	this->_index = 0;
	return ;
}

PhoneBook::~PhoneBook( void )
{
	return ;
}

void	setValue( Contact &contact, const std::string var )
{
	std::string	aux;

	std::cout << var << ": ";
	std::cin >> aux;
	contact.set(var, aux);
}

void	PhoneBook::add( void )
{
	std::string	aux;

	if (this->_index == 8)
		this->_index = 0;
	setValue(this->_contacts[this->_index], "firstName");
	setValue(this->_contacts[this->_index], "lastName");
	setValue(this->_contacts[this->_index], "nickname");
	setValue(this->_contacts[this->_index], "phoneNumber");
	setValue(this->_contacts[this->_index], "darkestSecret");
	++this->_index;
}

void	header( void )
{
	std::string	divider(52, '-');

	std::cout << divider << std::endl;
	std::cout << "|   INDEX   |";
	std::cout << " FIRST NAME |";
	std::cout << " FIRST NAME |";
	std::cout << "  NICKNAME  |" << std::endl;
	std::cout << divider << std::endl;
}

void	PhoneBook::search( void )
{
	int			index = 0;

	while (index < 8 && !this->_contacts[index].get("firstName").empty())
	{
		if (!index)
			header();
		++index;
	}
}
