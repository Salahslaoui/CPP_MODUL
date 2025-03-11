/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:13:54 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/11 21:02:38 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fract_bit = 8;

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->value = src.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf (nb * float(1 << fract_bit));
}


Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = nb * (1 << fract_bit);
}

int Fixed::get_fract()
{
	return(fract_bit);
}

int Fixed::getRawBits() const
{
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
} 

int		Fixed::toInt() const
{
	return (this->value / (1 << fract_bit));
}

float	Fixed::toFloat() const 
{
	return ((float)this->value / float(1 << fract_bit));
}
