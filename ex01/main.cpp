/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:15:34 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/14 19:08:59 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	// Check deep copy Cat
    Cat     a;
	Cat		b;

	a.setIdea("My name is Silvestre");
	b.setIdea("My name is Kobu");
	a = b;
	std::cout << "A: " << a.getIdea(0) << " ";
    a.makeSound();
	std::cout << "B: " << b.getIdea(0) << " ";
    b.makeSound();
    std::cout << std::endl;

    // Check deep copy Dog
    Dog     c;
	Dog		d;

	c.setIdea("My name is Toby");
	c = d;
	std::cout << "C: " << c.getIdea(0) << " ";
    c.makeSound();
    d.setIdea("My name is Petra");
	std::cout << "D: " << d.getIdea(0) << " ";
    d.makeSound();
    std::cout << std::endl;

    // Check destruction order
    const Animal    *j = new Dog();
    const Animal    *x = new Cat();
	
    j->makeSound();
    x->makeSound();
    delete x;
    delete j;
    std::cout << std::endl;

    //Check array of animals
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
