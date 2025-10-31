/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:00:17 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/14 09:00:18 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class   AAnimal
{
    public:
    	//Constructors
        AAnimal( void );
		AAnimal( const AAnimal &cpy );
		//Operators
		AAnimal  &operator=( const AAnimal &rhs );
		//Destructor
		virtual ~AAnimal( void );
		// Member functions
        virtual void	makeSound( void ) const = 0;
        std::string		getType( void ) const;

    protected:
        std::string type;
};
#endif /* AAnimal */