/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:46:05 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/22 03:45:56 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("Salah");
	ClapTrap c(b);

	std::cout << c.get_name() << std::endl;
	a.attack("Demon");
	a.takeDamage(1000);
	a.beRepaired(2);
	a.beRepaired(2);
	a.beRepaired(2);
	a.beRepaired(2);
	a.beRepaired(2);
	a.attack("Demon");
	a.attack("Demon");
	a.attack("Demon");
	a.attack("Demon");
	a.attack("Demon");
	b.attack("Demon");
	b = a;
	std::cout << b.get_Energy() << std::endl;
	b.takeDamage(2);
	b.beRepaired(2);
}