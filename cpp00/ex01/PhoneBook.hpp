/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:01:16 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/26 17:25:18 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>	// string

class	PhoneBook
{
	public:
		PhoneBook( void );
		~PhoneBook( void );

		void		add( Contact *contacts );	//setter
		std::string	search( void );				//getter
	
	private:
		static	_index;
		Contact	_contacts[8];
};

#endif
