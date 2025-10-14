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

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
    const AAnimal    *cat = new Cat();
    //const AAnimal   error;

    cat->makeSound();
    delete cat;
    return (0);
}