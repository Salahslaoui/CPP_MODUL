/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 02:17:26 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/22 03:41:09 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat created!!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destroyed!!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "meow meow" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Cat	&Cat::operator=(const Cat &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->type = src.type;
	return (*this);
}
