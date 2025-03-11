/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:45:15 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/11 17:55:24 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	value;
		static const int fract_bit;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const float a);
		Fixed(const int b);
		Fixed &operator=(const Fixed &src);
		bool operator<(const Fixed &src);
		bool operator>(const Fixed &src);
		bool operator>=(const Fixed &src);
		bool operator<=(const Fixed &src);
		bool operator==(const Fixed &src);
		bool operator!=(const Fixed &src);
		Fixed &operator+(const Fixed &src);
		Fixed &operator-(const Fixed &src);
		Fixed &operator*(const Fixed &src);
		Fixed &operator/(const Fixed &src);
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed static &min(Fixed &obj1, Fixed &obj2);
		Fixed const static &min(Fixed const &obj1, Fixed const &obj2);
		Fixed static &max(Fixed &obj1, Fixed &obj2);
		Fixed const static &max(Fixed const &obj1, Fixed const &obj2);
		Fixed &operator++();
		Fixed &operator--();

		~Fixed();
		int		getRawBits(void) const;
		int get_fract();
		void	setRawBits(int const raw);
		int		toInt() const;
		float		toFloat() const;
};

#endif
