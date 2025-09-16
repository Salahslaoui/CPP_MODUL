/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:32:08 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/19 12:53:00 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << "Copy constructed created" << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = src.name;
	this->Hit_point = src.Hit_point;
	this->Energy_point = src.Energy_point;
	this->Attack_damage = src.Attack_damage;
	return (*this);
}

void ScavTrap::guardGate()
{
	if (Hit_point <= 0)
	{
		std::cout << "No Hit point left" << std::endl;
		return ;
	}
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
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
	std::cout << "ScavTrap " << name << " attacks " << target << " causing " << Attack_damage << " points of damage!" << std::endl;
	Energy_point--;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destoyed" << std::endl;
}
