/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:59:18 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/19 11:40:35 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Demon");
	ScavTrap b("Salah");
	ScavTrap c;

	c = a;
	a.guardGate();
	b.attack("Demon");
	std::cout << c.get_name() << std::endl;
}