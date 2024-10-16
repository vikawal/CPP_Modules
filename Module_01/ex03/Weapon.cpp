/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:25:03 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/11 14:31:33 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//constructor definition
Weapon::Weapon(std::string type) : _type(type) 
//: _type(type) initializer list for parameter we pass to computer
{
	// The constructor doesn't do anything inside the body 
	//->necessary initialization has already happened in 
	//the initializer list (_type(type)).
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string Weapon::getType(void)
{
	return (this->_type);
}

Weapon::~Weapon(void)
{
	
}