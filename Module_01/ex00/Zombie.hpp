/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:04:28 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/11 11:24:29 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	_name;
	
	public:
	//Constructor - initiating
	Zombie(std::string name);
	
	//Destructor - cleaning
	~Zombie(void);
	
	//Member functions
	void	announce(void);
};

// stack memory allocation
void	randomChump(std::string name);

// heap memory allocation with pointer, NEW and DELETE
Zombie*	newZombie(std::string name);

#endif