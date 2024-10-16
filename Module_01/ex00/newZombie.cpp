/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:17:01 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/11 11:24:52 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// heap memory allocation with pointer, NEW and DELETE
Zombie*	newZombie(std::string name)
{
	Zombie *newZombie = new Zombie(name);
	return (newZombie);
}