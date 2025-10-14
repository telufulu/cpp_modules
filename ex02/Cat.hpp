/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:26:59 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/14 09:27:00 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class   Cat:    public AAnimal
{
    public:
        //Constructor
        Cat( void );
        Cat( const Cat &cpy );
		//Operators
		Cat  &operator=( const Cat &rhs );
        //Destructor
        ~Cat( void );
        //Member functions
        virtual void makeSound ( void ) const;
        
    private:
        Brain   *_brain;
};
#endif /* CAT */
