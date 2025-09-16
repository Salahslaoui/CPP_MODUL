/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 02:10:29 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/22 09:52:51 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Animal created!!" << std::endl;
}

Animal::Animal(std::string src) : type(src)
{
	std::cout << "Animal created!!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destroyed!!" << std::endl;
}

const std::string Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Animal	&Animal::operator=(const Animal &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->type = src.type;
	return (*this);
}
