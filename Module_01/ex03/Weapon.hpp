/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:18:12 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/11 14:23:11 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon 
{
	private:
		std::string _type;
	
	public:
		Weapon(std::string type);
		
		std::string getType(void);
		void setType(std::string type);
		
		~Weapon();
};

#endif