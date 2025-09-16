/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:27:15 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/21 23:52:18 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <unistd.h>

int	comp_s1(std::string str, char *s1, int i, int len)
{
	int j;

	j = 0;
	while (str[i] && j < len)
	{
		if (str[i] == s1[j])
		{
			j++;
			i++;
			continue;
		}
		else
		{	std::cout << str[i];
			return (0);}
	}
	if (j == len)
		return (1);
	return (0);
}

void	check_line(std::string str, char *s1, char *s2, int len, std::ofstream &nw_file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (comp_s1(str, s1, i, len))
		{
			nw_file << s2;
			i += len - 1;
			if (i == 0)
				return ;
		}
		else 
			nw_file << str[i];
		i++;
	}
		nw_file << std::endl;
}

int main(int ac, char **av)
{
	std::ofstream	nw_file;
	std::ifstream	pr_file;
	std::string		str;
	std::string		ptr;
	int				len;

	if (ac != 4)
		return (std::cout << "error in arguments number !" << std::endl, 1);
	pr_file.open(av[1], std::fstream::in | std::fstream::out);
	if (pr_file.fail())
		return (std::cout << "Error in opening file" << std::endl, 1);
	ptr = av[2];
	if (ptr.compare("") == 0)
		return (1);
	len = ptr.length();
	ptr = av[1];
	ptr = ptr + ".replace";
	nw_file.open(ptr);
	while (std::getline(pr_file, str))
	{
		check_line(str, av[2], av[3], len, nw_file);
	}
}
