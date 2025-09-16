/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:31:41 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/22 14:10:44 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	int	i;


	i = 0;
	while (i < 100)
	{
		ideas[i] = "idea";
		i++;
	}
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(std::string src)
{
	int	i;


	i = 0;
	while (i < 100)
	{
		ideas[i] = src;
		i++;
	}
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
}

Brain	&Brain::operator=(const Brain &src)
{
	int i = 0;
	while (i < 100)
	{
		this->ideas[i] = src.ideas[i];
		i++;
	}
	return(*this);
}

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}
