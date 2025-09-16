/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:42:43 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/22 06:32:23 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	FragTrap a("Salah");

	a.attack("Demon");
    a.takeDamage(30);
	a.attack("Demon");
    a.takeDamage(30);
	a.attack("Demon");
    a.takeDamage(30);
	a.attack("Demon");
    a.takeDamage(30);
    a.highFivesGuys(); 
}
