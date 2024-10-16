/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:12:58 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/11 17:39:00 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	int amountZombies = 5;
	Zombie *Horde = zombieHorde(amountZombies, "Zombie_1");
	Horde[1].setName("Zombie_2");
	// Horde[2].setName("Zombie_3");
	// Horde[3].setName("Zombie_4");
	Horde[4].setName("Zombie_5");
	for (int i = 0; i < amountZombies; i++)
		Horde[i].announce();
	delete [] Horde; //delete works in reverse order of creation
	return (0);

}