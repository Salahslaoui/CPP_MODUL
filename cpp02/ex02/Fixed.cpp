/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:13:54 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/11 18:12:20 by sslaoui          ###   ########.fr       */
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

bool Fixed::operator<(const Fixed &src)
{
	if (this->value < src.value)
		return (1);
	return (0);
}

bool Fixed::operator>(const Fixed &src)
{
	if (this->value > src.value)
		return (1);
	return (0);
}

bool Fixed::operator<=(const Fixed &src)
{
	if (this->value <= src.value)
		return (1);
	return (0);
}

bool Fixed::operator>=(const Fixed &src)
{
	if (this->value >= src.value)
		return (1);
	return (0);
}

bool Fixed::operator==(const Fixed &src)
{
	if (this->value == src.value)
		return (1);
	return (0);
}

Fixed &Fixed::operator+(const Fixed &src)
{
	this->value += src.value;
	return (*this);
}

Fixed &Fixed::operator-(const Fixed &src)
{
	this->value -= src.value;
	return (*this);
}

Fixed &Fixed::operator*(const Fixed &src)
{
	this->value *= src.value;
	return (*this);
}

Fixed &Fixed::operator/(const Fixed &src)
{
	this->value /= src.value;
	return (*this);
}

bool Fixed::operator!=(const Fixed &src)
{
	if (this->value != src.value)
		return (1);
	return (0);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->value++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->value--;
	return (tmp);
}

Fixed &Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf (nb * float(1 << fract_bit));
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return (obj1);
	return (obj2);
}

Fixed const &Fixed::min(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return (obj1);
	return (obj2);
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return (obj1);
	return (obj2);
}

Fixed const &Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return (obj1);
	return (obj2);
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = nb;
}

int Fixed::getRawBits() const
{
	return (value);
}

int Fixed::get_fract()
{
	return (fract_bit);
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
