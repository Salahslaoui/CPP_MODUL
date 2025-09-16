/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:42:20 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/16 19:36:36 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &Wp) : name(str), weapon(Wp) {

}

void	HumanA::attack()
{
	std::cout << HumanA::name << " attacks with their " << weapon.getType() << std::endl;
}