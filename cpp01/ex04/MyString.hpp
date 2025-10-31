/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:12:28 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/08 18:12:29 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSTRING_HPP
# define MYSTRING_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class	MyString
{
	public:
		MyString ( char *file );
		~MyString( void );

		int		replace( std::string oldString, std::string newString );

		std::string	file;

	private:
		MyString( void );

		std::string	_filename;

};

#endif /* MyString */