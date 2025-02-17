/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 08:39:40 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/02 16:26:34 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	std::string	str;
	int			i;
	int			j;

	i = 1;
	j = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (av[i])
		{
			str = av[i];
			while (str[j])
				std::cout << (char)toupper(str[j++]);
			j = 0;
			i++;
		}
		std::cout << std::endl;
	}
}