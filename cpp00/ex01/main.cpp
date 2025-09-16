/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:52:55 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 05:08:42 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	check_char(std::string str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (isprint(str[i]));
		else
			return(1);
		if (str[i] == ' ')
			j++;
		i++;
	}
	if (i == j)
		return(1);
	return (0);
}

Contact	Contact_fill(void )
{
	Contact	Cn;
	std::string	str;

	while(1)
	{
		std::cout << "first name: ";
		std::getline(std::cin, str, '\n');
		if (std::cin.eof())
			exit(0);
		if (str == "" || check_char(str))
			continue;
		else
		{
			Cn.set_info(str, 0);
			break;
		}
	}
	while(1)
	{
		std::cout << "last name: ";
		std::getline(std::cin, str, '\n');
		if (std::cin.eof())
			exit(0);
		if (str == "" || check_char(str))
			continue;
		else
		{
			Cn.set_info(str, 1);
			break;
		}
	}
	while(1)
	{
		std::cout << "nickname: ";
		std::getline(std::cin, str, '\n');
		if (std::cin.eof())
			exit(0);
		if (str == "" || check_char(str))
			continue;
		else
		{
			Cn.set_info(str, 2);
			break;
		}
	}
	while(1)
	{
		std::cout << "phone number: ";
		std::getline(std::cin, str, '\n');
		if (std::cin.eof())
			exit(0);
		if (str == "" || check_char(str))
			continue;
		else
		{
			Cn.set_info(str, 3);
			break;
		}
	}
	while(1)
	{
		std::cout << "darkest secret: ";
		std::getline(std::cin, str, '\n');
		if (std::cin.eof())
			exit(0);
		if (str == "" || check_char(str))
			continue;
		else
		{
			Cn.set_info(str, 4);
			break;
		}
	}
	return (Cn);
}

std::string	trim_char(std::string str)
{
	char		ptr[11];
	int			i;

	i = 0;
	if (str.length() == 10)
		return (str);
	else if (str.length() < 10)
	{
		while (str[i])
		{
			ptr[i] = str[i];
			i++;
		}
		while (i < 10)
		{
			ptr[i] = ' ';
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	else
	{
		while(i < 9)
		{
			ptr[i] = str[i];
			i++;
		}
		ptr[i++] = '.';
		ptr[i] = '\0';
		return (ptr);
	}
}

void	print_info(PhoneBook Ph)
{
	std::string	str;
	Contact	Cn;
	int	i;

	i = 0;
	std::cout << "index     |first name|last name | nickname |" << std::endl;
	while (i < 8)
	{
		Cn = Ph.get_cont(i);
		std::cout << (i + 1) << "         " << '|';
		std::cout << trim_char(Cn.get_info(0)) << '|';
		std::cout << trim_char(Cn.get_info(1)) << '|';
		std::cout << trim_char(Cn.get_info(2)) << '|';
		std::cout << std::endl;
		i++;
	}
}

int	check_ptr(std::string ptr)
{
	int	i;

	i = 0;
	if (ptr[i] < '0' || ptr[i] > '8')
		return (0);
	return (ptr[i]);
}

void	print_Cn(Contact Cn)
{
	std::cout << "first name: " << Cn.get_info(0) << std::endl;
	std::cout << "last name: " << Cn.get_info(1) << std::endl;
	std::cout << "nickname: " << Cn.get_info(2) << std::endl;
	std::cout << "Phone number: " << Cn.get_info(3) << std::endl;
	std::cout << "darkest secret: " << Cn.get_info(4) << std::endl;
}

void	select_print(PhoneBook Ph)
{
	std::string	ptr;
	Contact	Cn;
	int	i;

	i = 0;
	while (1)
	{
		if (std::cin.eof())
			exit(1);
		std::cout << "-> Please enter index from 1 to 8 or 0 to exit !!" << std::endl;
		std::getline(std::cin, ptr);
		if (ptr.length() != 1)
			continue ;
		if ((i = check_ptr(ptr)))
			break;
	}
	i -= 48;
	if (i != 0)
	{
		i -= 1;
		Cn = Ph.get_cont(i);
		print_Cn(Cn);
	}
}

int main()
{
	std::string str;
	std::string ptr;
	PhoneBook	Ph;
	Contact		Cn;
	int			i;

	i = 0;
	while (1)
	{
		std::cout << "-> Please enter ADD, SEARCH or EXIT !!" << std::endl;
		std::getline(std::cin, ptr, '\n');
		if (std::cin.eof())
			exit(1);
		if (ptr.compare("ADD") == 0)
		{
			Cn = Contact_fill();
			Ph.set_cont(Cn, i);
			i++;
			if (i == 8)
				i = 0;
		}
		else if (ptr.compare("SEARCH") == 0)
		{
			print_info(Ph);
			select_print(Ph);
		}
		else if (ptr.compare("EXIT") == 0)
			return (0);
	}
	return 0;
}
