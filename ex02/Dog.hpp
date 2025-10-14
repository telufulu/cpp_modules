/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:26:59 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/14 09:27:00 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class   Dog:    public AAnimal
{
    public:
        //Constructor
        Dog( void );
        Dog( const Dog &cpy );
		//Operators
		Dog  &operator=( const Dog &rhs );
        //Destructor
        ~Dog( void );
        //Member functions
        virtual void makeSound ( void ) const;
    
    private:
        Brain   *_brain;
};
#endif /* DOG */
