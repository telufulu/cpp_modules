/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:12:19 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/08 18:12:22 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyString.hpp"
#include "Utils.hpp"

MyString::MyString ( char *file ) : _filename(file)
{
	std::ifstream		infile;
	std::ostringstream	ostring;

	infile.open(file, std::ifstream::in);
	if (!infile.is_open())
		error("File doesn't exist");
	ostring << infile.rdbuf();
	infile.close();
	this->file = ostring.str();
	return ;
}

MyString::~MyString( void )
{
	return ;
}

int	MyString::replace( std::string oldString, std::string newString)
{
	std::ofstream	outfile;
	std::string		aux;
	int				pos = 0;
	int				i = 0;

	outfile.open(this->_filename + ".replace");
	if (!outfile.is_open())
		return (error("Unable to create result.txt"));
	if (oldString.empty())
		outfile << this->file;
	while (pos != -1)
	{
		pos = this->file.find(oldString, i);
		if (pos != -1)
		{
			aux.append(this->file, i, pos - i);
			aux.append(newString);
			i = pos + oldString.size();
		}
	}
	aux.append(this->file, i, this->file.size() - i);
	outfile << aux;
	outfile.close();
	return (0);
}