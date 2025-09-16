/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:10:02 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/13 22:46:34 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string *stringREF;
	std::string str;

	std::string& stringPTR = str;
	stringREF = &str;
	str = "HI THIS IS BRAIN";
	std::cout << "The memory address of the string variable : " << &str << std::endl;
	std::cout << "The memory address held by stringREF : " << stringREF << std::endl;
	std::cout << "The memory address held by stringPTR : " << &stringPTR << std::endl;
	std::cout << "The value of the string variable : " << str << std::endl;
	std::cout << "The value pointed to by stringPTR : " << stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF : " << *stringREF << std::endl;
}