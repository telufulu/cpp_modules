/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:28:23 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/10 13:28:24 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyString.hpp"
#include "Utils.hpp"

int main( int argc, char **argv )
{
	MyString		infile( argv[1] );

	if (argc != 4 || !*argv[1] || !*argv[2])
		return (error("Wrong arguments"));
	if (infile.replace(argv[2], argv[3]))
		return (1);
	return (0);
}