/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:15:34 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/14 09:15:35 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
    const Animal    *j = new Dog();
    const Animal    *x = new Cat();
    const Cat       a;

    a.makeSound();
    j->makeSound();
    delete x;
    x = j;
    x->makeSound();
    delete j;

    const Animal    *farm[100];
    int             i = 0;

    while (i < 50)
        farm[i++] = new Dog();
    while (i < 100)
        farm[i++] = new Cat();
    farm[0]->makeSound();
    farm[50]->makeSound();
    while (i--)
        delete farm[i];

    const Animal *p = new Dog();
    const Animal *q = p;

    q->makeSound();
    delete p;
    return (0);
}