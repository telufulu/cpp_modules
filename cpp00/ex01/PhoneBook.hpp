/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:01:16 by telufulu          #+#    #+#             */
/*   Updated: 2025/08/27 14:08:52 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>	// string

class	PhoneBook
{
	public:
		PhoneBook( void );
		~PhoneBook( void );

		void	add( void );	//setter
		void	search( void );	//getter
	
	private:
		int		_index;
		Contact	_contacts[8];
};

#endif
