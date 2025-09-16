/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:37:13 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/16 16:21:20 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string in)
{
	type = in;
}

std::string	Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string Upd)
{
	type = Upd;
}