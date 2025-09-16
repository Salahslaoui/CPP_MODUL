/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:42:23 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/19 01:49:46 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "HumanA.hpp"
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon	*weapon;
	public:
		HumanB(std::string str);
		void	setWeapon(Weapon *Wp);
		void	attack();
};
