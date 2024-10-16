/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:32:36 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/15 11:23:12 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon &_weapon; //// Reference to a Weapon object
		//HumanA is always armed, using a reference here & ->
		// it guarantees the weapon cannot be NULL, 
		//and it must always reference a valid weapon.
		
//References must be initialized when declared, and they cannot be null or uninitialized. 
//-> you can always safely use a reference without needing to check if it points to something valid.

	public:
		HumanA(std::string name, Weapon& weapon);

		void attack(void);
		void setName(std::string name);
		
		~HumanA(void);
};

#endif