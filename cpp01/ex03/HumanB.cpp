/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:42:17 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/25 23:45:20 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon *Wp) 
{
	weapon = Wp;
}

HumanB::HumanB(std::string str) : name(str), weapon(NULL)
{
}

void	HumanB::attack()
{
	if (!weapon)
	{
		std::cout << "there is no weapon!!!" << std::endl;
		return ;
	}
	std::cout << HumanB::name << " attacks with their " << (*weapon).getType() << std::endl;
}