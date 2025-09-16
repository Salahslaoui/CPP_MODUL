/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:18:11 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/22 03:44:54 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), Hit_point(100), Energy_point(50), Attack_damage(20)
{
	std::cout << "ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string src) : name(src), Hit_point(100), Energy_point(50), Attack_damage(20)
{
	std::cout << "ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor created" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = src.name;
	this->Hit_point = src.Hit_point;
	this->Energy_point = src.Energy_point;
	this->Attack_damage = src.Attack_damage;
	return (*this);
}

unsigned int ClapTrap::get_Energy()
{
	return (Energy_point);
}

std::string ClapTrap::get_name()
{
	return (name);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << Attack_damage << " points of damage!" << std::endl;
	Energy_point--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (Hit_point <= 0)
	{
		std::cout << "No Hit point left" << std::endl;
		return ;
	}
	if (Attack_damage > Hit_point)
	{
		std::cout << name << "has taken damage more than he can afford, Dead!!" << std::endl;
		Hit_point = 0;
		return ;
	}
	if (Hit_point >= amount)
		Hit_point -= amount;
	else
		Hit_point = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Hit_point <= 0)
	{
		std::cout << "No Hit point left" << std::endl;
		return ;
	}
	if (Energy_point <= 0)
	{
		std::cout << "No energy point left" << std::endl;
		return ;
	}
	Hit_point += amount;
	Energy_point--;
	std::cout << "ClapTrap repaired itself!!" << std::endl;
}
