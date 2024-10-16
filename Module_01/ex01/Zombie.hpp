/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:57:22 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/11 12:10:01 by vmyshko          ###   ########.fr       */
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
	Zombie(void);
	
	//Destructor - cleaning
	~Zombie(void);
	
	//Member functions
	//setter
	void	setName(std::string name);
	//getter
	std::string	getName(void);
	void	announce(void);
};


// heap memory allocation with pointer, NEW and DELETE
Zombie* zombieHorde( int N, std::string name );

#endif