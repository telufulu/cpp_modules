/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:12:19 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/08 18:12:22 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <string>

int main(int argc, char **argv)
{
    std::string	filename = argv[1];
    std::string	s1 = argv[2];
    std::string	s2 = argv[3];

	checkArgs();
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (!argc)
		return(1);
	return (0);
}