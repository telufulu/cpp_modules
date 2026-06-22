/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:41:41 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/22 11:41:42 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void)
{
    // Empty array
	std::cout << "\033[90mEMPTY ARRAY\033[0m" << std::endl;
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;
	std::cout << std::endl;

    // Constructor with size
	std::cout << "\033[90mCONSTRUCTOR WITH SIZE\033[0m" << std::endl;
    Array<int> a(5);
    std::cout << "a.size() = " << a.size() << std::endl;
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = i * 10;
    std::cout << "a: ";
    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl << std::endl;

    // Copy constructor
	std::cout << "\033[90mCOPY CONSTRUCTOR\033[0m" << std::endl;
    Array<int> b(a);
    b[0] = 999;
    std::cout << "a[0] = " << a[0] << " | b[0] = " << b[0] << std::endl;
	std::cout << std::endl;
	// Si a[0] sigue siendo 0 y b[0] es 999 -> copia profunda OK
    // Si a[0] cambió a 999 -> copia superficial (BUG)

    // Operator=
	std::cout << "\033[90mOPERATOR =\033[0m" << std::endl;
    Array<int> c;
    c = a;
    c[1] = -1;
    std::cout << "a[1] = " << a[1] << " | c[1] = " << c[1] << std::endl;

    try
    {
        std::cout << "Intentando a[42]..." << std::endl;
        std::cout << a[42] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Excepcion capturada: " << e.what() << std::endl;
    }
	std::cout << std::endl;

    // Const construction
	std::cout << "\033[90mCONST CONSTRUCTION\033[0m" << std::endl;
    const Array<int> d(a);
    std::cout << "d[2] = " << d[2] << std::endl;
    // d[2] = 5;   // <- no compila a propósito (es const)

	return 0;
}
