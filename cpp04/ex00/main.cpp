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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
    std::cout << "***** Normal classes *****" << std::endl;
    const Animal* i = new Cat();
    const Animal* j = new Dog();

    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    delete j;
    delete i;

    std::cout << "\n***** Wrong classes *****" << std::endl;
    const WrongAnimal* w = new WrongCat();

    std::cout << w->getType() << std::endl;
    w->makeSound();
    delete w;
    return (0);
}