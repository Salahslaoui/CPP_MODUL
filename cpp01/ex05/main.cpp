/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 03:47:03 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/25 15:47:09 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	comp;
	if (ac != 2)
	{
		std::cout << "Wrong arguments !!!";
		return (1);
	}
	comp.complain(av[1]);
}