/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 02:16:53 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/22 14:32:13 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Cat created!!" << std::endl;
	brain = new Brain;
}

Dog::Dog(std::string src) : Animal("Dog")
{
	std::cout << "Dog created!!" << std::endl;
	brain = new Brain(src);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destroyed!!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Dog	&Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		delete this->brain;
		this->type = src.type;
		this->brain = new Brain;
		for (int i = 0; i < 100; i++)
			this->brain[i] = src.brain[i];
	}
	return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
}
