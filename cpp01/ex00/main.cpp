/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:34:12 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/26 02:12:07 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *add;

	add = new Zombie;
	add->set_name(name);
	return (add);
}

void randomChump(std::string name)
{
	Zombie add;

	add.set_name(name);
	add.announce();
}

int main()
{
	randomChump("Foo");
}
