/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 05:03:36 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 05:06:15 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_info(int i)
{
	if (i == 0)
		return (first_name);
	else if (i == 1)
		return (last_name);
	else if (i == 2)
		return (nickname);
	else if (i == 3)
		return (phone_number);
	else if (i == 4)
		return (darkest_secret);
	return (NULL);
}

void	Contact::set_info(std::string str, int i)
{
	if (i == 0)
		first_name = str;
	else if (i == 1)
		last_name = str;
	else if (i == 2)
		nickname = str;
	else if (i == 3)
		phone_number = str;
	else if (i == 4)
		darkest_secret = str;
}
