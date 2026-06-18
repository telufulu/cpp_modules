/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:47:53 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/18 12:47:55 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main ( void )
{
	Data	d;
	Data	*ptr;
	uintptr_t	raw;

	d.id = 42;
	d.name = "Lufu";
	raw = Serializer::serialize(&d);
	ptr = Serializer::deserialize(raw);
	std::cout << "Original address: " << &d << std::endl;
	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << "Deserialized value: " << ptr << std::endl;
	if (ptr == &d)
		std::cout << "Pointer test: ✅" << std::endl;
	else
		std::cout << "Pointer test: ❌" << std::endl;
	return 0;
}
