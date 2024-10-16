/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:43:01 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/15 11:12:29 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) // no weapon
{
	
}

void HumanB::setName(std::string name)
{
	this->_name = name;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	this->_weapon = &newWeapon;
}

void HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon" << std::endl;
}

HumanB::~HumanB(void)
{
	
}