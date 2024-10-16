/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:37:02 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/15 11:11:53 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon; //// Pointer to a Weapon object
		// HumanB might not always have a weapon, a pointer is BEST choice ->. 
		// A pointer can be set to NULL (or nullptr in modern C++), 
		// it allows us to check if HumanB has a weapon or not.


	public:
		HumanB(std::string name);

		void attack(void);
		void setName(std::string name);
		void setWeapon(Weapon& weapon);
		
		~HumanB(void);
};

#endif