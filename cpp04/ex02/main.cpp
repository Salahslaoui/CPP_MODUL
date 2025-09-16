/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 02:05:36 by sslaoui           #+#    #+#             */
/*   Updated: 2025/03/22 14:36:03 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void l()
{
	system("leaks a.out");
}

int main()
{
	atexit(l);
	Animal *A[4];
	int i;

	i = 0;
	while (i < 2)
	{
		A[i] = new Dog();
		i++; 
	}
	while (i < 4)
	{
		A[i] = new Cat();
		i++; 
	}
	i = 0;
	while (i < 4)
	{
		A[i]->makeSound ();
		i++; 
	}
	i = 0;
	while (i < 4)
	{
		delete A[i];
		i++; 
	}
}
