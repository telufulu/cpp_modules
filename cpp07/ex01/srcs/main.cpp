/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:06:10 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/22 11:06:11 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
# include <iostream>				// ostream
#include <string>

template <typename T>
void    print(const T &x)
{
    std::cout << x << "\t";
}

template <typename T>
void    increment(T &x)
{
    x += 1;
}

void    shout(std::string &s)
{
    s += "!";
}

int main(void)
{
    int		arr[] = {1, 2, 3, 4, 5};
    size_t	len = sizeof(arr) / sizeof(arr[0]);

	print("*****\tINT\t*****");
	std::cout << std::endl;
    print("Original:");
    iter(arr, len, print<int>);
    std::cout << std::endl;

    iter(arr, len, increment<int>);
    print("Increment:");
    iter(arr, len, print<int>);
    std::cout << std::endl;

	std::cout << std::endl;
	print("*****\tSTRING\t*****");
	std::cout << std::endl;
    std::string words[] = {"hola", "mundo", "cpp"};
    size_t wlen = sizeof(words) / sizeof(words[0]);

    iter(words, wlen, shout);
    iter(words, wlen, print<std::string>);
    std::cout << std::endl;

    return 0;
}