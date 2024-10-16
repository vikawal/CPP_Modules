/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:21:08 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/11 11:35:12 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	//stack
	Zombie Stack("Stack");
	Stack.announce();

	//heap
	Zombie *Heap = newZombie("Heap");
	Heap->announce();
	
	//free heap memory
	delete Heap; 
	//function call
	//internal in randomChump function stack allocation
	randomChump("Random");
	
	

	return (0);
}