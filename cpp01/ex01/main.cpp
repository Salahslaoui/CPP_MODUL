/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:20:06 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/25 23:41:05 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*add;
	int		i;

	i = 0;
	add = new(std::nothrow) Zombie[N];
	if (add == NULL)
		return (NULL);
	while (i < N)
	{
		add[i].set_name(name);
		i++;
	}
	return (add);
}

int main()
{
	Zombie	*add;
	int		i;

	i = 0;
	add = zombieHorde(8, "Foo");
	while (add && i < 8)
	{
		add[i].announce();
		i++;
	}
	delete[] add;
}