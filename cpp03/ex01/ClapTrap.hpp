/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:46:46 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/22 04:17:27 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CPP
#define CLAPTRAP_CPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int Hit_point;
		unsigned int Energy_point;
		unsigned int Attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string src);
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator=(const ClapTrap &src);
		virtual ~ClapTrap();
		unsigned int get_Energy();
		std::string get_name();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
