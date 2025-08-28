/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:01:10 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/28 16:47:47 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>			// setw

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
	std::string	divider(53, '-');

	std::cout << divider << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << " FIRST NAME" << "|";
	std::cout << std::setw(10) << " LAST NAME" << "|";
	std::cout << std::setw(10) << " NICKNAME" << "|" << std::endl;
	std::cout << divider << std::endl;
}

void	getValues( Contact &contact, const int index )
{
	std::string	aux;

	std::cout << "| " << std::setw(10) << index;
	aux = contact.get("firstName");
	std::cout << "| " << std::setw(10) << aux.substr(0, 9) << ".";
	aux = contact.get("lastName");
	std::cout << "| " << std::setw(10) << aux.substr(0, 9) << ".";
	aux = contact.get("nickname");
	std::cout << "| " << std::setw(10) << aux.substr(0, 9) << ".\n";
}

void	PhoneBook::search( void )
{
	int			index;
	std::string	input;
	std::string	divider(53, '-');

	while (input != "E")
	{
		index = 0;
		std::cout << "\033[2J\033[1;1H";
		if (this->_contacts[index].get("firstName").empty())
			std::cout << "No data\n";
		else
			header();
		while (index < 8 && !this->_contacts[index].get("firstName").empty())
		{
			getValues(this->_contacts[index], index);
			++index;
		}
		std::cout << divider << std::endl;
		std::cout << "\n(Type E to exit)\n";
		std::cin >> input;
	}
}
