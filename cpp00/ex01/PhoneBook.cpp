/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 05:03:56 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 05:07:37 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact PhoneBook::get_cont(int i)
{
	return (cont[i]);
}
void	PhoneBook::set_cont(Contact upd, int i)
{
	cont[i] = upd;
}
