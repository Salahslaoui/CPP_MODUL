/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:57:59 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/11 21:05:17 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int32_t	FloatToFixed(float d, Fixed tst)
{
	int s = tst.get_fract();

	return (d * float(1 << s));
}

float FixedToFloat(int32_t d, Fixed tst)
{
	int s = tst.get_fract();
	return (d / float(1 << s));
}

std::ostream &operator<< (std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}

int main() 
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}