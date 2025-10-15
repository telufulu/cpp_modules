/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:15:19 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/15 09:06:04 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class   Brain
{
    public:
		//Constructor
        Brain( void );
        Brain( const Brain &cpy );
		//Operators
		Brain  &operator=( const Brain &rhs );
        //Destructor
        ~Brain( void );
		//Member functions
		void	setIdea( std::string idea );
		const	std::string &getIdea( int i ) const;

    private:
        std::string _ideas[100];
};
#endif /* BRAIN */
