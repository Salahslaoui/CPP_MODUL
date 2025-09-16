/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 02:17:26 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/22 14:31:16 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat created!!" << std::endl;
	brain = new Brain;
}

Cat::Cat(std::string src) : Animal("Cat")
{
	std::cout << "Cat created!!" << std::endl;
	brain = new Brain(src);
}

Cat::~Cat()
{
	std::cout << "Cat Destroyed!!" << std::endl;
	delete brain;
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

Brain Cat::getter()
{
	return (brain[0]);
}

Cat	&Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		delete this->brain;
		this->type = src.type;
		this->brain = new Brain;
		for (int i = 0; i < 100; i++)
		{
			this->brain[i] = src.brain[i];
		}
	}
	return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
}
