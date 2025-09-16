/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:50:39 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/20 01:08:44 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FtagTrap created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "Copy constructed created" << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = src.name;
	this->Hit_point = src.Hit_point;
	this->Energy_point = src.Energy_point;
	this->Attack_damage = src.Attack_damage;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (Hit_point <= 0)
	{
		std::cout << "No Hit point left" << std::endl;
		return ;
	}
	std::cout << "FragTrap requesting a high fives!!!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (Energy_point <= 0)
	{
		std::cout << "No Energy point left" << std::endl;
		return ;
	}
	if (Hit_point <= 0)
	{
		std::cout << "No Hit point left" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " attacks " << target << " causing " << Attack_damage << " points of damage!" << std::endl;
	Energy_point--;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destoyed" << std::endl;
}
