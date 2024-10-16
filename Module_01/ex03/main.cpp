/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:54:12 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/15 11:26:47 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

/* Human B is not always armed with a weapon, so we store his weapon as a pointer,
this way it can store null when calling the constructor.

We pass as reference to avoid copying big objects hence we don't allocate extra heap
memory so we optimize performance */

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("shitty club"); // // Automatically managed memory on stack
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club++");
		jim.attack();
	}
	return (0);
}